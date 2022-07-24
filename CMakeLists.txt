cmake_minimum_required(VERSION 3.7)
project(pixel_engine VERSION 1.0)

set(SOURCES src/main.cc src/Application.cc src/Window.cc)
include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(X11 REQUIRED)

add_executable(pixel_engine ${SOURCES})
target_link_libraries(pixel_engine PUBLIC Vulkan::Vulkan glfw X11 Xxf86vm Xrandr Xi Xrender ${CMAKE_DL_LIBS})
