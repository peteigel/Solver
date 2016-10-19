#ifndef inc_sudoku
#define inc_sudoku

#include <array>
#include <exception>
#include <stdexcept>

// A change

namespace sudoku {
	template <std::size_t max_val>
	class Cell {
		std::array<bool, max_val> data;
	public:
		Cell();
		Cell(int value);
		bool& access (const int value);
		const bool& access (const int value) const;
		int num_possible() const;
		int value() const;
		void set_value(const int value);

		void operator= (const int& v) { set_value(v); };
		bool operator== (const int& v) const { return value() == v; };
		bool operator!= (const int& v) const { return value() != v; };
		bool& operator[] (std::size_t v) { return access(v); };
		const bool& operator[] (std::size_t v) const { return access(v); };
	};

	template <std::size_t _n = 3>
	class Puzzle {
		static constexpr std::size_t _max_val = _n * _n;
		static constexpr std::size_t _n_cells = _max_val * _max_val;

		std::array<Cell<_max_val>, _n_cells> cells;
	public:
		std::size_t n () const { return _n; };
		std::size_t max_val () const { return _max_val; };
		std::size_t num_cells () const { return _n_cells; };

		const std::array<Cell<_max_val>, _n_cells>& access() const;
		std::array<Cell<_max_val>, _n_cells>& access();
		const Cell<_max_val>& access (const std::size_t row, const std::size_t col) const;
		Cell<_max_val>& access (const std::size_t row, const std::size_t col);

		std::array<Cell<_max_val>*, _max_val> row (const std::size_t r);
		std::array<Cell<_max_val>*, _max_val> col (const std::size_t c);
		std::array<Cell<_max_val>*, _max_val> box (const std::size_t b);
		std::array<Cell<_max_val>*, _max_val> group (const std::size_t g);
	};

	class invalid_puzzle : public std::logic_error {
		using std::logic_error::logic_error;
	};
}

#endif
