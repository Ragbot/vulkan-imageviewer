cmake_minimum_required(VERSION 3.0)

project(gl_app VERSION 1.0.0)

add_executable(gl_app main.cpp AppWindow.cpp AppWindow.h app.cpp app.h AppPipeline.cpp AppPipeline.h AppDevice.cpp AppDevice.h)

find_package(glfw3 3.3 REQUIRED)

target_link_libraries(gl_app curl ncurses glfw vulkan)