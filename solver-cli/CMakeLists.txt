file(GLOB SOURCE_FILES src/*.cpp)
add_executable(solver ${SOURCE_FILES})
target_link_libraries(solver sudoku)

file(TO_NATIVE_PATH solver-cli/test/evil_puzzle.csv TEST_PUZZLE)
add_test(NAME solver-cli-test COMMAND solver ${TEST_PUZZLE} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
