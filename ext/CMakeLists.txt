# Glad
add_subdirectory(glad-learn-opengl/)

# GLFW
if(RASPBIAN AND RPI_HAS_NEON)
    add_compile_options(-mfpu=neon)
endif()

set(GLFW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glfw-dev)
add_subdirectory(${GLFW_DIR})
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Imgui
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
add_library(imgui STATIC)

target_sources( imgui
        PRIVATE
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui.cpp

        PRIVATE
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        )

target_include_directories( imgui
        PUBLIC ${IMGUI_DIR}
        PUBLIC ${IMGUI_DIR}/backends
        PUBLIC ${GLFW3_DIR}/include/GLFW
        )

if(USE_GLES OR RASPBIAN)
    target_compile_definitions(imgui PUBLIC -DIMGUI_IMPL_OPENGL_ES2)

    if(RASPBIAN AND RPI_USE_BROADCOM_DRIVER)
        target_link_directories(imgui PUBLIC /opt/vc/lib)
        target_link_libraries(imgui PUBLIC brcmGLESv2 brcmEGL)
    else()
        target_link_libraries(imgui PUBLIC GLESv2)
    endif()
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(imgui PUBLIC ${OPENGL_LIBRARIES})
endif()


target_link_libraries(imgui PUBLIC ${CMAKE_DL_LIBS})

# STB

add_library(stb STATIC
        stb/stb_c_lexer.h
        stb/stb_connected_components.h
        stb/stb_divide.h
        stb/stb_ds.h
        stb/stb_dxt.h
        stb/stb_easy_font.h
        stb/stb_herringbone_wang_tile.h
        stb/stb_hexwave.h
        stb/stb_image_resize.h
        stb/stb_image_write.h
        stb/stb_include.h
        stb/stb_image.h
        stb/stb_leakcheck.h
        stb/stb_perlin.h
        stb/stb_rect_pack.h
        stb/stb_sprintf.h
        stb/stb_textedit.h
        stb/stb_tilemap_editor.h
        stb/stb_truetype.h
        stb/stb_vorbis.c
        stb/stb_voxel_render.h)
set_target_properties(stb PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(stb PUBLIC stb)
