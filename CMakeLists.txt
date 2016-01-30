cmake_minimum_required (VERSION 3.2)

project (Solver)

set(CMAKE_BUILD_TYPE Debug)

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory (src)
add_subdirectory (test)
