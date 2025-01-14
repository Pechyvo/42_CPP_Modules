#include "Phonebook.hpp"

void add(Phonebook &phonebook);
bool numberFormat(std::string str);
void search(Phonebook &phonebook);
bool index(Phonebook &phonebook, std::string str);
#ifdef DEBUG
void debug(Phonebook &phonebook);
#endif

int main() {
	Phonebook   phonebook;
	std::string input;

	while (1) {
		std::cout << YELLOW << "Enter a command: " << RESET;
		if (!std::getline(std::cin, input)) {
			std::cout << "\n";
			break;
		}
		else if (input == "ADD")
			add(phonebook);
		else if (input == "SEARCH")
		    search(phonebook);
		else if (input == "EXIT")
			break;
		#ifdef DEBUG
		else if (input == "debug")
			debug(phonebook);
		#endif
		else if (input == "HELP")
		#ifdef DEBUG
			std::cout << GREEN << "Available commands: " << U_GREEN << "ADD" << GREEN << ", " << U_GREEN << "SEARCH" << GREEN << " and " << U_GREEN << "EXIT" << GREEN << " + debug" << std::endl;
		#else
			std::cout << GREEN << "Available commands: " << U_GREEN << "ADD" << GREEN << ", " << U_GREEN << "SEARCH" << GREEN << " and " << U_GREEN << "EXIT" << RESET << std::endl;
		#endif
		else
			std::cout << RED << "Unknown command. " << BLUE << "Use " << U_BLUE << "HELP" << BLUE << " to see available commands." << RESET << std::endl;
	}

	return 0;
}

void add(Phonebook &phonebook) {
	Contact contact;
	std::string input;

	do {
		std::cout << YELLOW << "Enter the contact's name: " << RESET << std::endl;
	} while ((std::getline(std::cin, input)) && input.empty());
	contact.setName(input);

	do {
		std::cout << YELLOW << "Enter the contact's surname: " << RESET << std::endl;
	} while ((std::getline(std::cin, input)) && input.empty());
	contact.setSurname(input);

	do {
		std::cout << YELLOW << "Enter the contact's nickname: " << RESET << std::endl;
	} while ((std::getline(std::cin, input)) && input.empty());
	contact.setNickname(input);

	do {
		std::cout << YELLOW << "Enter the contact's phone number: " << RESET << std::endl;
	} while ((std::getline(std::cin, input)) && !numberFormat(input));
	contact.setNumber(input);

	do {
		std::cout << YELLOW << "Enter the contact's darkest secret: " << RESET << std::endl;
	} while ((std::getline(std::cin, input)) && input.empty());
	contact.setSecret(input);

	phonebook.addContact(contact);
}

bool numberFormat(std::string str) {
	if (str.empty())
		return false;
	for (std::size_t i = 0; i < str.size(); i++) {
		if ((str[i] >= '0' && str[i] <= '9'))
			continue;
		else {
			std::cout << RED << "Entry can only contain numbers." << RESET << std::endl;
			return false;
		}
	}
	return true;
}

void search(Phonebook &phonebook) {
	std::string input;

	if (phonebook.getContactQuantity() < 1) {
        std::cout << RED << "Phonebook is empty." << std::endl << RESET;
        return ;
    }
	phonebook.displayPhonebook();
	do {
		std::cout << YELLOW << "Enter the index of the contact you want to view(1-8): " << RESET << std::endl;
	} while ((std::getline(std::cin, input)) && !index(phonebook, input));
	phonebook.displayContact(atoi(input.c_str()) - 1);
}

bool index(Phonebook &phonebook, std::string str) {
	int value;

	if (!numberFormat(str))
		return false;
	value = atoi(str.c_str());
	if (value > 0 && value <= phonebook.getContactQuantity())
		return true;
	return false;
}

#ifdef DEBUG
void debug(Phonebook &phonebook) {
	static int d = 0;
	Contact contact;
	std::string name[] = {"John", "Jane", "Jack", "Jill", "Jim", "Jenny", "Jesse", "Jasmine"};
	std::string surname[] = {"Doe", "Smith", "Johnson", "Brown", "Davis", "Miller", "Wilson", "Moore"};
	std::string nickname[] = {"JD", "JS", "JJ", "JB", "JD", "JM", "JW", "JM"};
	std::string number[] = {"123456789", "987654321", "123123123", "321321321", "456456456", "654654654", "789789789", "987987987"};
	std::string secret[] = {"gardening", "cooking", "reading", "swimming", "running", "cycling", "hiking", "dancing"};
	if (d == 1)
	{
		contact.setName("Mikeeeeeeeeeeeeeeee");
		contact.setSurname("Wazoooooooooooooooooo");
		contact.setNickname("Eyeeeeeeeeeeeeeeeeee");
		contact.setNumber("123123123123123123123123123");
		contact.setSecret("comic");
		phonebook.addContact(contact);
		return;
	}
	for (int i = 0; i < 8 && d == 0; i++) {
		contact.setName(name[i]);
		contact.setSurname(surname[i]);
		contact.setNickname(nickname[i]);
		contact.setNumber(number[i]);
		contact.setSecret(secret[i]);
		phonebook.addContact(contact);
	}
	d = 1;
}
#endif
