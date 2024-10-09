#include "phonebook.hpp"

Phonebook::Phonebook()
{
	this->index = 0;
	std::cout << CYAN << "Phonebook opened! There is space for 8 contacts." << RESET << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << PURPLE << "Phonebook was closed!" << RESET << std::endl;
}

void    addContact(void)
{
	
}

void    searchContact(void)
{

}
