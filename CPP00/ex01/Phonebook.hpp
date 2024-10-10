#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Formatting.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int		index;
	public:
		Phonebook();
		~Phonebook();
		void    addContact(void);
		void    searchContact(void);
};

#endif