#include "Formatting.hpp"
#include <iostream>

int main(int argc, char **argv) {
    int i = -1;
    int j;
    if (argc < 2)
        std::cout << YELLOW <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << RESET;
    while (argc > 1 && argv && argv[++i])
    {
        j = -1;
        while (i > 0 && argv[i][++j])
            std::cout << CYAN << (char)toupper(argv[i][j]) << RESET;
    }
    std::cout << std::endl;
    return 0;
}
