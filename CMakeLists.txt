cmake_minimum_required(VERSION 3.7)
project(vulkan_engine VERSION 1.0)

set(SOURCES
    src/main.cc
    src/Application.cc
    src/Window.cc
    src/Camera.cc
    src/Vulkan/VulkanContext.cc)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Vulkan REQUIRED)
find_package(X11 REQUIRED)

add_subdirectory(extern/glfw)

add_executable(vulkan_engine ${SOURCES})
target_link_libraries(vulkan_engine PUBLIC Vulkan::Vulkan glfw X11 Xxf86vm Xrandr Xi Xrender ${CMAKE_DL_LIBS})
