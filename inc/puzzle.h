#ifndef inc_puzzle
#define inc_puzzle

#include <array>

template <std::size_t max_val>
class Cell {
	std::array<bool, max_val> data;
};

template <std::size_t n = 3>
class Puzzle {
	static constexpr std::size_t max_val = n * n;
	static constexpr std::size_t n_cells = max_val * max_val;

	std::array<Cell<max_val>, n_cells> cells;
public:
	Cell<max_val>& access (const std::size_t row, const std::size_t col);
	std::array<Cell<max_val>*, max_val> row (const std::size_t r);
	std::array<Cell<max_val>*, max_val> col (const std::size_t c);
	std::array<Cell<max_val>*, max_val> box (const std::size_t b);
	void print_max_val ();
};

#endif
