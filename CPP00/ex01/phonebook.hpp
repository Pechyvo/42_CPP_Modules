#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include "formatting.hpp"

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