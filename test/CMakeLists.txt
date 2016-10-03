file (GLOB TEST_CASES *.spec.cpp)
add_executable(solver_tests main.cpp ${TEST_CASES})
target_link_libraries(solver_tests gtest sudoku)
add_test(NAME solver_tests COMMAND solver_tests)
