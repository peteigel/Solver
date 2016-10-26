#include "sudoku/io.h"

// This file is ridiculous. C++17 inline variables will eliminate it soon.
std::ostream* sudoku::io::log = nullptr;
