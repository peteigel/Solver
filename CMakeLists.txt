cmake_minimum_required (VERSION 3.2)

project (Solver)

set(CMAKE_BUILD_TYPE Debug)

enable_testing()

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories (inc)
add_subdirectory (src)
add_subdirectory (test)
add_subdirectory (vendor/googletest)
