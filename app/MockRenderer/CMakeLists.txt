cmake_minimum_required(VERSION 3.16)

project(MockRenderer VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

add_executable(MockRenderer
    src/main.cpp
    ${CMAKE_SOURCE_DIR}/deps/glad/src/glad.c)

target_include_directories(MockRenderer PRIVATE
    interface
    ${CMAKE_SOURCE_DIR}/deps/glad/include)

target_link_libraries(MockRenderer PRIVATE
    OpenGL::GL
    glfw)

set_target_properties(MockRenderer PROPERTIES FOLDER "App")
