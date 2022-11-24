cmake_minimum_required(VERSION 3.7)
project(vulkan_engine VERSION 1.0)

set(IMGUI_DIR extern/imgui)

set(SOURCES
    src/main.cc
    src/Application.cc
    src/Window.cc
    src/Camera.cc
    src/Vulkan/VulkanContext.cc

    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${IMGUI_DIR})
include_directories(${IMGUI_DIR}/backends)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Vulkan REQUIRED)
find_package(X11 REQUIRED)

add_subdirectory(extern/glfw)
add_subdirectory(extern/tinygltf)

add_executable(vulkan_engine ${SOURCES})
target_link_libraries(vulkan_engine PUBLIC Vulkan::Vulkan glfw tinygltf X11 Xxf86vm Xrandr Xi Xrender ${CMAKE_DL_LIBS})
