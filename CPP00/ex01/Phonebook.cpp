#include "Phonebook.hpp"

void truncate(std::string str);

Phonebook::Phonebook() {
	this->index = 0;
	std::cout << CYAN << "Phonebook opened! There is space for 8 contacts." << RESET << std::endl;
}

Phonebook::~Phonebook() {
	// std::cout << PURPLE << "Phonebook was closed!" << RESET << std::endl;
}

void Phonebook::addContact(Contact contact) {
	this->contacts[this->index] = contact;
	this->index = (this->index + 1) % 8;
}

int Phonebook::getContactQuantity() {
	int i = 0;

	while (i < 8 && !this->contacts[i].getName().empty()) {
		i++;
	}

	return i;
}

void Phonebook::displayPhonebook() {
	std::cout << CYAN << "•———————————————————————————————————————————•" << RESET << std::endl;
	std::cout<<CYAN<<"¦"<<PURPLE<<"     Index"<<CYAN<<"¦"<<PURPLE<<"First Name"<<CYAN<<"¦"<< PURPLE <<" Last Name"<<CYAN<<"¦"<<PURPLE<<"  Nickname"<<CYAN<<"¦"<<RESET<<std::endl;
	
	for (int i = 0; i < 8; i++) {
		if (!this->contacts[i].getName().empty()) {
			std::cout << CYAN << "¦" << BLUE << std::setw(10) << i + 1 << CYAN << "¦" << RESET;
			truncate(this->contacts[i].getName());
			truncate(this->contacts[i].getSurname());
			truncate(this->contacts[i].getNickname());
			std::cout << std::endl;
		}
	}
	std::cout << CYAN << "•———————————————————————————————————————————•" << RESET << std::endl;
}

void truncate(std::string str) {
	if (str.size() > 10)
		std::cout << GREEN << str.substr(0, 9) << "." << CYAN << "¦" << RESET;
	else {
		std::cout << GREEN << std::setw(10) << str;
		std::cout << CYAN << "¦" << RESET;
	}
}

void Phonebook::displayContact(int index) {
	std::cout << CYAN << "Contact details:" << RESET << std::endl;
	std::cout << PURPLE << "First Name: " << RESET << this->contacts[index].getName() << std::endl;
	std::cout << PURPLE << "Last Name: " << RESET << this->contacts[index].getSurname() << std::endl;
	std::cout << PURPLE << "Nickname: " << RESET << this->contacts[index].getNickname() << std::endl;
	std::cout << PURPLE << "Phone number: " << RESET << this->contacts[index].getNumber() << std::endl;
	std::cout << PURPLE << "Darkest secret: " << RESET << this->contacts[index].getSecret() << std::endl;
}
