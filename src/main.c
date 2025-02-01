#include <gtk/gtk.h>
#include <adwaita.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#define ASPECT_RATIO_COPY_TYPE_WINDOW (aspect_ratio_copy_window_get_type())
#define ASPECT_RATIO_COPY_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), ASPECT_RATIO_COPY_TYPE_WINDOW, AspectRatioCopyWindow))
#define ASPECT_RATIO_COPY_IS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), ASPECT_RATIO_COPY_TYPE_WINDOW))
#define ASPECT_RATIO_COPY_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), ASPECT_RATIO_COPY_TYPE_WINDOW, AspectRatioCopyWindowClass))
#define ASPECT_RATIO_COPY_IS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), ASPECT_RATIO_COPY_TYPE_WINDOW))
#define ASPECT_RATIO_COPY_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), ASPECT_RATIO_COPY_TYPE_WINDOW, AspectRatioCopyWindowClass))



typedef struct _AspectRatioCopyWindow AspectRatioCopyWindow;
typedef struct _AspectRatioCopyWindowClass AspectRatioCopyWindowClass;

struct _AspectRatioCopyWindow {
    AdwApplicationWindow parent_instance;
    GtkWidget *source_button;
    GtkWidget *dest_button;
    GtkDropDown *ratio_dropdown;
    GtkWidget *custom_ratio_entry;
    GtkWidget *custom_ratio_row;
    GtkScale *tolerance_scale;
    GtkLabel *tolerance_value;
    GtkButton *start_button;
    GtkProgressBar *progress_bar;
    GtkLabel *status_label;
    GtkListView *results_list;
    GListStore *results_model;
    char *source_path;
    char *dest_path;
    pthread_t processing_thread;
    gboolean processing;
    int total_files;
};

struct _AspectRatioCopyWindowClass {
    AdwApplicationWindowClass parent_class;
};

typedef struct {
    AspectRatioCopyWindow *window;
    double target_ratio;
    double tolerance;
} ThreadData;

typedef struct {
    AspectRatioCopyWindow *window;
    double progress;
    int processed_count;
    int total_files;
} ThreadProgressData;

typedef struct {
    AspectRatioCopyWindow *window;
    int processed_count;
    int copied_count;
} ProcessingCompleteData;

typedef struct {
    GObject parent_instance;
    char *filename;
    char *dimensions;
    double ratio;
    gboolean copied;
} ProcessedFile;

typedef struct {
    GObjectClass parent_class;
} ProcessedFileClass;

G_DEFINE_TYPE(ProcessedFile, processed_file, G_TYPE_OBJECT)
G_DEFINE_TYPE(AspectRatioCopyWindow, aspect_ratio_copy_window, ADW_TYPE_APPLICATION_WINDOW)

static gboolean add_result_idle(gpointer user_data);
static gboolean update_progress_idle(gpointer user_data);
static gboolean processing_complete_idle(gpointer user_data);



static const struct {
    const char *name;
    double ratio;
} COMMON_RATIOS[] = {
    {"3:4 (Portrait)", 0.75},
    {"2:3 (Manga)", 0.667},
    {"5:7 (Art Print)", 0.714},
    {"1:1 (Square)", 1.0},
    {"4:3 (Landscape)", 1.333},
    {"16:9 (Widescreen)", 1.778},
    {"Custom", 0.0}
};

static void
processed_file_init(ProcessedFile *self)
{
    self->filename = NULL;
    self->dimensions = NULL;
    self->ratio = 0.0;
    self->copied = FALSE;
}

static void
processed_file_finalize(GObject *object)
{
    ProcessedFile *self = (ProcessedFile *)object;
    g_free(self->filename);
    g_free(self->dimensions);
    G_OBJECT_CLASS(processed_file_parent_class)->finalize(object);
}

static void
processed_file_class_init(ProcessedFileClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);
    object_class->finalize = processed_file_finalize;
}

static ProcessedFile *
processed_file_new(const char *filename, const char *dimensions, double ratio, gboolean copied)
{
    ProcessedFile *file = g_object_new(processed_file_get_type(), NULL);
    file->filename = g_strdup(filename);
    file->dimensions = g_strdup(dimensions);
    file->ratio = ratio;
    file->copied = copied;
    return file;
}

static void process_directory(const char *source_dir, const char *base_source, 
                            const char *dest_dir, ThreadData *data,
                            int *total_processed, int *total_copied) {
    GDir *dir = g_dir_open(source_dir, 0, NULL);
    if (!dir) return;

    const char *name;
    while ((name = g_dir_read_name(dir))) {
        char *full_path = g_build_filename(source_dir, name, NULL);
        
        if (g_file_test(full_path, G_FILE_TEST_IS_DIR)) {
            // Calculate relative path
            char *rel_path = g_strdup(full_path + strlen(base_source) + 1);
            char *new_dest = g_build_filename(dest_dir, rel_path, NULL);
            
            // Create destination directory
            g_mkdir_with_parents(new_dest, 0755);
            
            // Recurse into subdirectory
            process_directory(full_path, base_source, dest_dir, data, 
                            total_processed, total_copied);
            
            g_free(rel_path);
            g_free(new_dest);
        } else if (g_str_has_suffix(name, ".jpg") ||
                  g_str_has_suffix(name, ".jpeg") ||
                  g_str_has_suffix(name, ".png") ||
                  g_str_has_suffix(name, ".gif") ||
                  g_str_has_suffix(name, ".webp")) {
            
            GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(full_path, NULL);
            if (pixbuf) {
                int width = gdk_pixbuf_get_width(pixbuf);
                int height = gdk_pixbuf_get_height(pixbuf);
                double actual_ratio = (double)width / height;
                
                // Calculate relative path for the file
                char *rel_path = g_strdup(full_path + strlen(base_source) + 1);
                char *rel_dir = g_path_get_dirname(rel_path);
                char *dest_subdir = g_build_filename(dest_dir, rel_dir, NULL);
                
                // Ensure destination subdirectory exists
                g_mkdir_with_parents(dest_subdir, 0755);
                
                char *dest_file = g_build_filename(dest_subdir, name, NULL);
                
                gboolean copied = fabs(actual_ratio - data->target_ratio) <= data->tolerance;
                
                // Create detailed status message
                char *status_msg = g_strdup_printf(
                    "File: %s\n"
                    "Dimensions: %dx%d\n"
                    "Actual ratio: %.3f\n"
                    "Target ratio: %.3f (±%.3f)\n"
                    "Result: %s",
                    rel_path, width, height, actual_ratio,
                    data->target_ratio, data->tolerance,
                    copied ? "COPYING" : "SKIPPING");
                
                g_print("%s\n\n", status_msg);
                g_free(status_msg);
                
                if (copied) {
                    if (g_file_copy(g_file_new_for_path(full_path),
                                  g_file_new_for_path(dest_file),
                                  G_FILE_COPY_NONE,
                                  NULL, NULL, NULL, NULL)) {
                        (*total_copied)++;
                    }
                }
                
                // Update GUI with result
                ProcessedFile *proc_file = processed_file_new(
                    rel_path, // Use relative path instead of just filename
                    g_strdup_printf("%dx%d", width, height),
                    actual_ratio,
                    copied);
                g_object_set_data(G_OBJECT(proc_file), "window", data->window);
                g_idle_add(add_result_idle, proc_file);
                
                g_free(rel_path);
                g_free(rel_dir);
                g_free(dest_subdir);
                g_free(dest_file);
                g_object_unref(pixbuf);
                
                (*total_processed)++;
                
                // Update progress
                ThreadProgressData *prog_data = g_new(ThreadProgressData, 1);
                prog_data->window = data->window;
                prog_data->progress = (double)*total_processed / data->window->total_files;
                prog_data->processed_count = *total_processed;
                prog_data->total_files = data->window->total_files;
                g_idle_add(update_progress_idle, prog_data);
            }
        }
        g_free(full_path);
    }
    g_dir_close(dir);
}

static void *
process_files(void *thread_data)
{
    ThreadData *data = (ThreadData *)thread_data;
    AspectRatioCopyWindow *win = data->window;
    
    // First pass: count total files recursively
    win->total_files = 0;
    GQueue *dirs = g_queue_new();
    g_queue_push_tail(dirs, g_strdup(win->source_path));
    
    while (!g_queue_is_empty(dirs)) {
        char *current_dir = g_queue_pop_head(dirs);
        GDir *dir = g_dir_open(current_dir, 0, NULL);
        
        if (dir) {
            const char *name;
            while ((name = g_dir_read_name(dir))) {
                char *full_path = g_build_filename(current_dir, name, NULL);
                
                if (g_file_test(full_path, G_FILE_TEST_IS_DIR)) {
                    g_queue_push_tail(dirs, g_strdup(full_path));
                } else if (g_str_has_suffix(name, ".jpg") ||
                          g_str_has_suffix(name, ".jpeg") ||
                          g_str_has_suffix(name, ".png") ||
                          g_str_has_suffix(name, ".gif") ||
                          g_str_has_suffix(name, ".webp")) {
                    win->total_files++;
                }
                g_free(full_path);
            }
            g_dir_close(dir);
        }
        g_free(current_dir);
    }
    g_queue_free(dirs);
    
    // Process files recursively
    int total_processed = 0;
    int total_copied = 0;
    process_directory(win->source_path, win->source_path, 
                     win->dest_path, data,
                     &total_processed, &total_copied);
    
    // Signal completion
    ProcessingCompleteData *complete_data = g_new(ProcessingCompleteData, 1);
    complete_data->window = win;
    complete_data->processed_count = total_processed;
    complete_data->copied_count = total_copied;
    g_idle_add(processing_complete_idle, complete_data);
    
    g_free(data);
    return NULL;
}

static const char *
get_selected_ratio_name(GtkDropDown *dropdown)
{
    guint selected = gtk_drop_down_get_selected(dropdown);
    GtkStringList *model = GTK_STRING_LIST(gtk_drop_down_get_model(dropdown));
    return gtk_string_list_get_string(model, selected);
}

static void
update_start_sensitivity(AspectRatioCopyWindow *win)
{
    const char *ratio_name = get_selected_ratio_name(win->ratio_dropdown);
    
    gboolean can_start = win->source_path != NULL && 
                        win->dest_path != NULL &&
                        (strcmp(ratio_name, "Custom") != 0 ||
                         strlen(gtk_editable_get_text(GTK_EDITABLE(win->custom_ratio_entry))) > 0);
                         
    gtk_widget_set_sensitive(GTK_WIDGET(win->start_button), can_start);
}

static gboolean
add_result_idle(gpointer user_data)
{
    ProcessedFile *file = (ProcessedFile *)user_data;
    AspectRatioCopyWindow *win = g_object_get_data(G_OBJECT(file), "window");
    g_list_store_append(win->results_model, file);
    g_object_unref(file);
    return G_SOURCE_REMOVE;
}

static gboolean
update_progress_idle(gpointer user_data)
{
    ThreadProgressData *prog_data = (ThreadProgressData *)user_data;
    AspectRatioCopyWindow *win = prog_data->window;
    
    gtk_progress_bar_set_fraction(win->progress_bar, prog_data->progress);
    
    char status_text[256];
    snprintf(status_text, sizeof(status_text), "Processing: %d/%d",
             prog_data->processed_count, prog_data->total_files);
    gtk_label_set_text(win->status_label, status_text);
    
    g_free(prog_data);
    return G_SOURCE_REMOVE;
}

static gboolean
processing_complete_idle(gpointer user_data)
{
    ProcessingCompleteData *complete_data = (ProcessingCompleteData *)user_data;
    AspectRatioCopyWindow *win = complete_data->window;
    
    gtk_progress_bar_set_fraction(win->progress_bar, 1.0);
    
    char status_text[256];
    snprintf(status_text, sizeof(status_text),
             "Complete! Processed %d files, copied %d",
             complete_data->processed_count,
             complete_data->copied_count);
    gtk_label_set_text(win->status_label, status_text);
    
    gtk_widget_set_sensitive(GTK_WIDGET(win->start_button), TRUE);
    win->processing = FALSE;
    
    g_free(complete_data);
    return G_SOURCE_REMOVE;
}

static void
on_folder_selected(GtkFileDialog *dialog, GAsyncResult *result, AspectRatioCopyWindow *win)
{
    GtkButton *button = GTK_BUTTON(g_object_get_data(G_OBJECT(dialog), "target_button"));
    GFile *file = gtk_file_dialog_select_folder_finish(dialog, result, NULL);
    
    if (file) {
        char *path = g_file_get_path(file);
        char *basename = g_path_get_basename(path);
        
        gtk_button_set_label(button, basename);
        
        if (button == GTK_BUTTON(win->source_button)) {
            g_free(win->source_path);
            win->source_path = g_strdup(path);
        } else {
            g_free(win->dest_path);
            win->dest_path = g_strdup(path);
        }
        
        g_free(basename);
        g_free(path);
        g_object_unref(file);
        
        update_start_sensitivity(win);
    }
    
    g_object_unref(dialog);
}

static void
on_folder_button_clicked(GtkButton *button, AspectRatioCopyWindow *win)
{
    GtkFileDialog *dialog = gtk_file_dialog_new();
    gtk_file_dialog_set_title(dialog, "Choose a folder");
    
    g_object_set_data(G_OBJECT(dialog), "target_button", button);
    gtk_file_dialog_select_folder(
        dialog,
        GTK_WINDOW(win),
        NULL,
        (GAsyncReadyCallback)on_folder_selected,
        win
    );
}

static void
on_ratio_changed(GtkDropDown *dropdown, GParamSpec *pspec, AspectRatioCopyWindow *win)
{
    const char *ratio_name = get_selected_ratio_name(dropdown);
    gtk_widget_set_visible(win->custom_ratio_row, strcmp(ratio_name, "Custom") == 0);
    update_start_sensitivity(win);
}

static void
on_start_clicked(GtkButton *button, AspectRatioCopyWindow *win)
{
    if (win->processing) {
        return;
    }
    
    double target_ratio;
    const char *ratio_name = get_selected_ratio_name(win->ratio_dropdown);
    
    if (strcmp(ratio_name, "Custom") == 0) {
        const char *custom_ratio = gtk_editable_get_text(GTK_EDITABLE(win->custom_ratio_entry));
        target_ratio = atof(custom_ratio);
        if (target_ratio <= 0) {
            return;
        }
    } else {
        for (size_t i = 0; i < G_N_ELEMENTS(COMMON_RATIOS); i++) {
            if (strcmp(COMMON_RATIOS[i].name, ratio_name) == 0) {
                target_ratio = COMMON_RATIOS[i].ratio;
                break;
            }
        }
    }
    
    double tolerance = gtk_range_get_value(GTK_RANGE(win->tolerance_scale));
    
    g_list_store_remove_all(win->results_model);
    gtk_progress_bar_set_fraction(win->progress_bar, 0);
    gtk_widget_set_sensitive(GTK_WIDGET(win->start_button), FALSE);
    gtk_label_set_text(win->status_label, "Scanning files...");
    
    ThreadData *thread_data = g_new(ThreadData, 1);
    thread_data->window = win;
    thread_data->target_ratio = target_ratio;
    thread_data->tolerance = tolerance;
    
    win->processing = TRUE;
    pthread_create(&win->processing_thread, NULL, process_files, thread_data);
}

static void
setup_list_item(GtkListItemFactory *factory, GtkListItem *list_item)
{
    GtkBox *box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6));
    gtk_widget_set_margin_start(GTK_WIDGET(box), 6);
    gtk_widget_set_margin_end(GTK_WIDGET(box), 6);
    gtk_widget_set_margin_top(GTK_WIDGET(box), 3);
    gtk_widget_set_margin_bottom(GTK_WIDGET(box), 3);
    
    GtkImage *icon = GTK_IMAGE(gtk_image_new());
    gtk_image_set_icon_size(icon, GTK_ICON_SIZE_LARGE);
    gtk_box_append(box, GTK_WIDGET(icon));
    
    GtkBox *vbox = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
    GtkLabel *filename_label = GTK_LABEL(gtk_label_new(NULL));
    gtk_widget_add_css_class(GTK_WIDGET(filename_label), "heading");
    gtk_label_set_xalign(filename_label, 0);
    
    GtkLabel *details_label = GTK_LABEL(gtk_label_new(NULL));
    gtk_widget_add_css_class(GTK_WIDGET(details_label), "caption");
    gtk_label_set_xalign(details_label, 0);
    
    gtk_box_append(vbox, GTK_WIDGET(filename_label));
    gtk_box_append(vbox, GTK_WIDGET(details_label));
    gtk_box_append(box, GTK_WIDGET(vbox));
    
    gtk_list_item_set_child(list_item, GTK_WIDGET(box));
}

static void
bind_list_item(GtkListItemFactory *factory, GtkListItem *list_item)
{
    GtkBox *box = GTK_BOX(gtk_list_item_get_child(list_item));
    GtkImage *icon = GTK_IMAGE(gtk_widget_get_first_child(GTK_WIDGET(box)));
    GtkBox *vbox = GTK_BOX(gtk_widget_get_next_sibling(GTK_WIDGET(icon)));
    GtkLabel *filename_label = GTK_LABEL(gtk_widget_get_first_child(GTK_WIDGET(vbox)));
    GtkLabel *details_label = GTK_LABEL(gtk_widget_get_next_sibling(GTK_WIDGET(filename_label)));
    
    ProcessedFile *file = gtk_list_item_get_item(list_item);
    
    gtk_label_set_text(filename_label, file->filename);
    
    char details[256];
    snprintf(details, sizeof(details), "%s - Ratio: %.3f%s",
             file->dimensions, file->ratio,
             file->copied ? "" : " (Outside target range)");
    gtk_label_set_text(details_label, details);
    
    gtk_image_set_from_icon_name(
        icon,
        file->copied ? "object-select-symbolic" : "window-close-symbolic"
    );
}

static void
aspect_ratio_copy_window_init(AspectRatioCopyWindow *self)
{
    // Initialize template
    gtk_widget_init_template(GTK_WIDGET(self));
    
    self->source_path = NULL;
    self->dest_path = NULL;
    self->processing = FALSE;
    self->total_files = 0;
    
    // Set up ratio dropdown
    GtkStringList *string_list = gtk_string_list_new(NULL);
    for (size_t i = 0; i < G_N_ELEMENTS(COMMON_RATIOS); i++) {
        gtk_string_list_append(string_list, COMMON_RATIOS[i].name);
    }
    
    g_return_if_fail(GTK_IS_DROP_DOWN(self->ratio_dropdown));
    gtk_drop_down_set_model(self->ratio_dropdown, G_LIST_MODEL(string_list));
    g_object_unref(string_list);
    
    // Connect signals
    g_signal_connect(self->ratio_dropdown, "notify::selected",
                    G_CALLBACK(on_ratio_changed), self);
    g_signal_connect(self->source_button, "clicked",
                    G_CALLBACK(on_folder_button_clicked), self);
    g_signal_connect(self->dest_button, "clicked",
                    G_CALLBACK(on_folder_button_clicked), self);
    g_signal_connect(self->start_button, "clicked",
                    G_CALLBACK(on_start_clicked), self);
    
    // Set up results list
    GtkListItemFactory *factory = gtk_signal_list_item_factory_new();
    g_signal_connect(factory, "setup", G_CALLBACK(setup_list_item), NULL);
    g_signal_connect(factory, "bind", G_CALLBACK(bind_list_item), NULL);
    
    gtk_list_view_set_factory(self->results_list, factory);
    g_object_unref(factory);
    
    self->results_model = g_list_store_new(G_TYPE_OBJECT);
    GtkSelectionModel *selection_model = GTK_SELECTION_MODEL(
        gtk_single_selection_new(G_LIST_MODEL(self->results_model))
    );
    gtk_list_view_set_model(self->results_list, selection_model);
    g_object_unref(selection_model);
    
    update_start_sensitivity(self);
}

static void
aspect_ratio_copy_window_dispose(GObject *object)
{
    AspectRatioCopyWindow *self = ASPECT_RATIO_COPY_WINDOW(object);
    
    g_clear_pointer(&self->source_path, g_free);
    g_clear_pointer(&self->dest_path, g_free);
    
    G_OBJECT_CLASS(aspect_ratio_copy_window_parent_class)->dispose(object);
}

static void
aspect_ratio_copy_window_class_init(AspectRatioCopyWindowClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);
    GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);
    
    object_class->dispose = aspect_ratio_copy_window_dispose;
    
    gtk_widget_class_set_template_from_resource(
        widget_class,
        "/com/example/AspectRatioCopy/window.ui"
    );
    
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, source_button);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, dest_button);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, ratio_dropdown);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, custom_ratio_entry);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, custom_ratio_row);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, tolerance_scale);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, tolerance_value);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, start_button);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, progress_bar);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, status_label);
    gtk_widget_class_bind_template_child(widget_class, AspectRatioCopyWindow, results_list);
}

static void
on_about_action(GSimpleAction *action, GVariant *parameter, gpointer user_data)
{
    GtkApplication *app = GTK_APPLICATION(user_data);
    GtkWindow *window = gtk_application_get_active_window(app);
    AdwAboutWindow *about = ADW_ABOUT_WINDOW(adw_about_window_new());
    
    adw_about_window_set_application_name(about, "Proportionate");
    adw_about_window_set_version(about, "1.0");
    adw_about_window_set_developer_name(about, "daftblazer");
    adw_about_window_set_website(about, "https://github.com/daftblazer");
    adw_about_window_set_issue_url(about, "https://github.com/daftblazer/proportionate/issues");
    adw_about_window_set_support_url(about, "https://github.com/daftblazer/proportionate/discussions");
    adw_about_window_set_copyright(about, "© 2025 daftblazer");
    const char *developers[] = {"daftblazer", NULL};
    adw_about_window_set_developers(about, developers);
    adw_about_window_set_application_icon(about, "org.gnome.Photos");
    
    gtk_window_set_transient_for(GTK_WINDOW(about), window);
    gtk_window_present(GTK_WINDOW(about));
}

static void
aspect_ratio_copy_app_startup(GApplication *app)
{
    G_APPLICATION_GET_CLASS(app)->startup(app);
    
    GActionEntry app_entries[] = {
        { "quit", NULL, NULL },
        { "about", on_about_action, NULL, NULL, NULL }
    };
    g_action_map_add_action_entries(G_ACTION_MAP(app), app_entries, G_N_ELEMENTS(app_entries), app);
    
    const char *accels[] = {"<primary>q", NULL};
    gtk_application_set_accels_for_action(GTK_APPLICATION(app), "app.quit", accels);
}

static void
aspect_ratio_copy_app_activate(GApplication *app)
{
    GtkWindow *window = gtk_application_get_active_window(GTK_APPLICATION(app));
    
    if (!window) {
        window = g_object_new(ASPECT_RATIO_COPY_TYPE_WINDOW,
                            "application", app,
                            NULL);
    }
    
    gtk_window_present(window);
}

int
main(int argc, char *argv[])
{
    g_autoptr(GtkApplication) app = gtk_application_new(
        "com.example.AspectRatioCopy",
        G_APPLICATION_DEFAULT_FLAGS
    );
    
    g_signal_connect(app, "activate", G_CALLBACK(aspect_ratio_copy_app_activate), NULL);
    g_signal_connect(app, "startup", G_CALLBACK(aspect_ratio_copy_app_startup), NULL);
    
    return g_application_run(G_APPLICATION(app), argc, argv);
}
