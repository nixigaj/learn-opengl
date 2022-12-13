find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(Freetype REQUIRED)

add_executable(simple-setup simple-setup.cpp)
target_link_libraries(simple-setup PUBLIC
        glad glfw imgui stb GLEW OpenGL glm ${FREETYPE_LIBRARIES})
target_include_directories(simple-setup PRIVATE ${FREETYPE_INCLUDE_DIRS})

add_executable(imgui-test imgui-test.cpp)
target_link_libraries(imgui-test PUBLIC
        glad glfw imgui stb GLEW OpenGL ${FREETYPE_LIBRARIES})
target_include_directories(imgui-test PRIVATE ${FREETYPE_INCLUDE_DIRS})

add_executable(hello-window hello-window.cpp)
target_link_libraries(hello-window PUBLIC
        glad glfw imgui stb GLEW OpenGL ${FREETYPE_LIBRARIES})
target_include_directories(hello-window PRIVATE ${FREETYPE_INCLUDE_DIRS})
