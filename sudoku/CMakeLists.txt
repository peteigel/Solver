file(GLOB SOURCE_FILES src/*.cpp)
add_library(sudoku ${SOURCE_FILES})
target_include_directories(sudoku PUBLIC inc)

file(GLOB TEST_CASES  test/*.spec.cpp)
add_executable(sudoku_tests test/main.cpp ${TEST_CASES})
target_link_libraries(sudoku_tests gtest sudoku)
add_test(NAME sudoku COMMAND sudoku_tests)
