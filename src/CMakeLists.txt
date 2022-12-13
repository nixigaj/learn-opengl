find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(simple-setup simple-setup.cpp)
target_link_libraries(simple-setup PUBLIC glad glfw GLEW::glew OpenGL::GL)

add_executable(hello-window hello-window.cpp)
target_link_libraries(hello-window PUBLIC glad glfw GLEW::glew OpenGL::GL)
