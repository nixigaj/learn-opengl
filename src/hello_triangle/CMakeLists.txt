add_executable(hello_triangle hello_triangle.cpp)
target_link_libraries(hello_triangle PRIVATE glad glfw glm)
target_include_directories(hello_triangle PUBLIC "${stb_SOURCE_DIR}")
