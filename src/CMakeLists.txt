find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(simple-setup simple-setup.cpp)
target_link_libraries(simple-setup PRIVATE glad glfw GLEW::glew OpenGL::GL)
