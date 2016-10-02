#ifndef inc_sudoku
#define inc_sudoku

#include <array>

namespace sudoku {
	template <std::size_t max_val>
	class Cell {
		std::array<bool, max_val> data;
	public:
		Cell();
		bool& access (const int value);
		const bool& access (const int value) const;
		int num_possible() const;
		int value() const;
		void set_value(const int value);
	};

	template <std::size_t _n = 3>
	class Puzzle {
		static constexpr std::size_t _max_val = _n * _n;
		static constexpr std::size_t _n_cells = _max_val * _max_val;

		std::array<Cell<_max_val>, _n_cells> cells;
	public:
		std::size_t n () const { return _n; };
		std::size_t max_val () const { return _max_val; };
		std::size_t n_cells () const { return _n_cells; };

		Cell<_max_val>& access (const std::size_t row, const std::size_t col);
		std::array<Cell<_max_val>*, _max_val> row (const std::size_t r);
		std::array<Cell<_max_val>*, _max_val> col (const std::size_t c);
		std::array<Cell<_max_val>*, _max_val> box (const std::size_t b);
	};
}

#endif
