#include "Harl.hpp"

int main(int argc, char **argv) {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

    if (argc != 2) {
        std::cerr << RED << "ERROR » " << CYAN << "Usage: " << YELLOW;
        std::cerr << argv[0] << " <level>" << RESET << std::endl;
        return 1;
    }

    std::string input(argv[1]);
    Harl complainerHarl;
    complainerHarl.complain(input);

    return 0;
}