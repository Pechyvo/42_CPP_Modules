#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << B_RED << "✗ Error: bad arguments" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: " << RESET << "./btc " << CYAN << "<inputFile>" << RESET << std::endl;
        std::cerr << std::endl << I_WHITE << "Example:" << RESET << std::endl;
        std::cerr << "  ./btc input.txt" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << B_RED << "✗ " << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}
