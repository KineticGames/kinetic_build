cmake_minimum_required(VERSION 3.24)
project(project)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake/modules/")

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib)

add_library(${PROJECT_NAME} src/library.c)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME})

if (${PROJECT_NAME}_BUILD_TESTS)
    add_subdirectory(test)
endif ()
