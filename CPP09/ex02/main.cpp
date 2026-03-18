#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << B_RED << "✗ Error: bad arguments" << RESET << std::endl;
		std::cerr << YELLOW << "Usage: " << RESET << "./PmergeMe "
			<< CYAN << "<positive integers...>" << RESET << std::endl;
		std::cerr << std::endl << I_WHITE << "Example:" << RESET << std::endl;
		std::cerr << "  ./PmergeMe 3 5 9 7 4" << std::endl;
		return 1;
	}

	try {
		PmergeMe app;
		app.run(argc, argv);
	} catch (const std::exception& e) {
		std::cerr << B_RED << "✗ " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
