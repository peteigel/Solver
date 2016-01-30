add_executable(Solver main.cpp)
add_library(puzzle puzzle.cpp cell.cpp cellGroup.cpp possibilities.cpp)
add_library(puzzlesolver solver.cpp)
add_library(puzzleio puzzleio.cpp)

target_link_libraries(Solver puzzle puzzlesolver puzzleio)
target_link_libraries(puzzlesolver puzzle)
target_link_libraries(puzzleio puzzle)

target_compile_features(puzzle PUBLIC cxx_nonstatic_member_init)
target_compile_features(puzzlesolver PUBLIC cxx_nonstatic_member_init)

include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/inc)
