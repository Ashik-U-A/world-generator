cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME WorldGenerator)
set(PROJECT_VERSION 1.0)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../bin)
set(ROOT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/include)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

add_subdirectory(lib/sources/glfw-3.3)
add_subdirectory(src/space)
add_subdirectory(src)