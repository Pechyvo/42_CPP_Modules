#include "../Formatting.hpp"
#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << CYAN << "The Memory Adresses:" << RESET << std::endl;
    std::cout << PURPLE << "The memory address of the string variable: " << BLUE << &str << RESET << std::endl;
    std::cout << PURPLE << "The memory address held by stringPTR: " << BLUE << stringPTR << RESET << std::endl;
    std::cout << PURPLE << "The memory address held by stringREF: " << BLUE << &stringREF << RESET << std::endl;

    std::cout << CYAN << "The Values:" << RESET << std::endl;
    std::cout << PURPLE << "The value of the string variable: " << BLUE << str << RESET << std::endl;
    std::cout << PURPLE << "The value pointed to by stringPTR: " << BLUE << *stringPTR << RESET << std::endl;
    std::cout << PURPLE << "The value pointed to by stringREF: " << BLUE << stringREF << RESET << std::endl;

    return 0;
}
