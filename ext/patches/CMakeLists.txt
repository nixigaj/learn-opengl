# TODO: Perform Git patch and unpatch before and after CMake build.

#ADD_CUSTOM_TARGET(do_always ALL)

#add_custom_command(TARGET do_always PRE_BUILD WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} COMMAND git apply ext/patches/glfw-dev.patch)
#add_custom_command(TARGET do_always POST_BUILD WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} COMMAND git apply --reverse ext/patches/glfw-dev.patch)
