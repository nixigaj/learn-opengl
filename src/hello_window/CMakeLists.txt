add_executable(hello_window hello_window.cpp)
target_link_libraries(hello_window PRIVATE glad glfw glm)
target_include_directories(hello_window PUBLIC "${stb_SOURCE_DIR}")
