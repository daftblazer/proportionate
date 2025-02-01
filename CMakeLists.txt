cmake_minimum_required(VERSION 3.10)
project(aspect-ratio-copy C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(DEPS REQUIRED
    gtk4
    libadwaita-1
    gdk-pixbuf-2.0
)

add_compile_options(${DEPS_CFLAGS})
include_directories(${DEPS_INCLUDE_DIRS})
link_directories(${DEPS_LIBRARY_DIRS})

# Generate resources
set(GRESOURCE_XML "${CMAKE_CURRENT_SOURCE_DIR}/data/com.example.AspectRatioCopy.gresource.xml")
set(GRESOURCE_C "${CMAKE_CURRENT_BINARY_DIR}/resources.c")

find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)

add_custom_command(
    OUTPUT ${GRESOURCE_C}
    COMMAND ${GLIB_COMPILE_RESOURCES}
    ARGS
        --target=${GRESOURCE_C}
        --sourcedir=${CMAKE_CURRENT_SOURCE_DIR}/data
        --generate-source
        ${GRESOURCE_XML}
    DEPENDS
        ${GRESOURCE_XML}
        data/window.ui
        data/aspect-ratio-copy.appdata.xml
    VERBATIM
)

add_executable(aspect-ratio-copy
    src/main.c
    ${GRESOURCE_C}
)

target_link_libraries(aspect-ratio-copy
    ${DEPS_LIBRARIES}
    pthread
)

install(TARGETS aspect-ratio-copy
    RUNTIME DESTINATION bin
)

install(FILES 
    data/aspect-ratio-copy.appdata.xml
    DESTINATION share/metainfo
)