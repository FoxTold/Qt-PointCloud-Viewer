cmake_minimum_required(VERSION 3.16)

project(DataGenerator VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(DataGenerator
            src/main.cpp)
            
set_target_properties(DataGenerator PROPERTIES FOLDER "App")
