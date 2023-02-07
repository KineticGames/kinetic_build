cmake_minimum_required(VERSION 3.24)
project(project)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake/modules/")

set(CMAKE_C_STANDARD 11)

add_executable(kinetic src/main.c)

target_include_directories(kinetic PRIVATE src)

