#include "Phonebook.hpp"

Phonebook::Phonebook() {
	this->index = 0;
	std::cout << CYAN << "Phonebook opened! There is space for 8 contacts." << RESET << std::endl;
}

Phonebook::~Phonebook() {
	std::cout << PURPLE << "Phonebook was closed!" << RESET << std::endl;
}

void    Phonebook::addContact() {
	std::string	name;

	std::cout << YELLOW << "Enter the name: " << RESET;
	std::getline(std::cin, name);
	contacts[this->index].setName(name);

	std::string	surname;
	std::cout << YELLOW << "Enter the surname: " << RESET;
	std::getline(std::cin, surname);
	contacts[this->index].setSurname(surname);
}

void    Phonebook::searchContact() {

}
