project('proportionate', 'c',
  version: '1.0.0',
  meson_version: '>= 0.59.0',
  default_options: [
    'warning_level=2',
    'werror=false',
    'c_std=c11',
  ],
)

# Dependencies
gtk_dep = dependency('gtk4')
libadwaita_dep = dependency('libadwaita-1')
gdk_pixbuf_dep = dependency('gdk-pixbuf-2.0')
threads_dep = dependency('threads')

# Configure application data
gnome = import('gnome')
resources = gnome.compile_resources('resources',
  'data/com.example.AspectRatioCopy.gresource.xml',
  source_dir: 'data',
  c_name: 'resources'
)

executable('proportionate',
  'src/main.c',
  resources,
  dependencies: [
    gtk_dep,
    libadwaita_dep,
    gdk_pixbuf_dep,
    threads_dep,
  ],
  install: true,
)

# Install metadata files
install_data(
  'data/aspect-ratio-copy.appdata.xml',
  install_dir: get_option('datadir') / 'metainfo'
)