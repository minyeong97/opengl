add_library ( gl3w STATIC gl3w.c )	

target_include_directories ( gl3w PRIVATE ${PROJECT_SOURCE_DIR}/include )
target_link_libraries ( gl3w PRIVATE dl )
