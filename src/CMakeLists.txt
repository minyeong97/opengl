add_subdirectory ( gl3w )

add_executable ( opengl main.cpp world.cpp camera.cpp )

target_include_directories ( opengl PRIVATE ${PROJECT_SOURCE_DIR}/include )
find_library ( GLFW_PATH NAMES glfw3 HINTS ${PROJECT_SOURCE_DIR}/lib )
target_link_libraries ( opengl PRIVATE ${GLFW_PATH} m dl pthread GL gl3w )
