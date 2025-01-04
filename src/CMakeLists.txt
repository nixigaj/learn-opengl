add_executable(hello_window hello_window.cpp)
target_link_libraries(hello_window PUBLIC
	glad glfw stb GLEW OpenGL)
