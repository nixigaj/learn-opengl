cmake_minimum_required(VERSION 3.11)
project(learn-opengl)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/)


## Dependencies ##
include(FetchContent)

# Glad
FetchContent_Declare(
		glad
		GIT_REPOSITORY https://github.com/nixigaj/glad-learn-opengl
		GIT_TAG        2a31b17610144a266a3cc67fae52640ecd5aac9c  # Feb 24, 2025
)
FetchContent_MakeAvailable(glad)

# GLFW
FetchContent_Declare(
		glfw
		GIT_REPOSITORY https://github.com/glfw/glfw
		GIT_TAG        3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# GLM
FetchContent_Declare(
		glm
		GIT_REPOSITORY https://github.com/g-truc/glm
		GIT_TAG        1.0.1
)
FetchContent_MakeAvailable(glm)

# stb
FetchContent_Declare(
		stb
		GIT_REPOSITORY https://github.com/nothings/stb
		GIT_TAG        5c205738c191bcb0abc65c4febfa9bd25ff35234  # Nov 9, 2024
)
FetchContent_MakeAvailable(stb)
