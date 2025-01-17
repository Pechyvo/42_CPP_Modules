#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Formatting.hpp"
#include <stdlib.h>
#include <iomanip>

class Phonebook {
	private:
		Contact contacts[8];
		int index;
	public:
		Phonebook();
		~Phonebook();
		void	addContact(Contact contact);
		int		getContactQuantity();
		void	displayPhonebook();
		void	displayContact(int index);
};

#endif