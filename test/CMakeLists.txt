file(GLOB UNIT_TESTS *_tests.cpp)

add_executable(tests main.cpp ${UNIT_TESTS})

target_link_libraries(tests puzzle puzzlesolver puzzleio)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/inc)
target_compile_features(tests PUBLIC cxx_uniform_initialization)
