#include "sudoku.h"
#include "sudoku/solver.h"
#include "sudoku/io.h"
#include <iostream>
#include <fstream>
#include <exception>

using namespace std;
using namespace sudoku;

int main (int argc, char** argv) {
	try {
		char* filename = argv[argc - 1];
		ifstream input (filename, ifstream::in);
		auto puz = io::read_puzzle<3>(input);

		cout << "Puzzle read successfully.\n";
		io::pretty_print(puz);

		io::enable_logging();
		auto result = solver::solve(puz, true);

		cout << "\n\n==============\n\n";

		if (result.num_solutions == 1) {
			cout << "Unique solution found:\n";
			io::pretty_print(result.solution);
		} else if (result.num_solutions == 0) {
			cout << "No solutions found.\n";
		} else if (result.num_solutions > 1) {
			cout << result.num_solutions << " solutions found:\n";
			io::pretty_print(result.solution);
		} else {
			cerr << "Unexpected solver result. Please report this bug.";
			return 1;
		}

		return 0;
	} catch (exception& e) {
		cerr << e.what() << '\n';
		return 1;
	}
}
