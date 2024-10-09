#include "phonebook.hpp"

int main(void)
{
    Phonebook   phonebook;
    std::string input;

    while (1)
    {
        std::cout << YELLOW << "Enter a command: " << RESET;
        std::getline(std::cin, input);
        if (!std::cin)
        {
            std::cout << "\n";
            break;
        }
        else if (input == "EXIT")
            break;
        else if (input == "ADD")
            /* phonebook.addContact() */;
        else if (input == "SEARCH")
            /* phonebook.searchContact() */;
        else if (input == "HELP")
            std::cout << GREEN << "Available commands: " << U_GREEN << "ADD" << GREEN << ", " << U_GREEN << "SEARCH" << GREEN << " and " << U_GREEN << "EXIT" << RESET << std::endl;
        else
            std::cout << RED << "Unknown command. " << BLUE << "Use " << U_BLUE << "HELP" << BLUE << " to see available commands." << RESET << std::endl;
    }
    return (0);
}
