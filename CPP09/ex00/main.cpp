#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << RED << "Error: bad arguments. Usage: ./btc <inputFile>" << RESET << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
