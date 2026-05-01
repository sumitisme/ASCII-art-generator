cmake_minimum_required(VERSION 3.10)

project(ASCII-art-generator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp include/*.hpp include/*.h)

add_executable(ASCII-generator ${SOURCE_FILES})