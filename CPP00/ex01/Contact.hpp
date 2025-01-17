#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	private:
		std::string name;
		std::string surname;
		std::string nickname;
		std::string number;
		std::string secret;
	public:
		Contact();
		~Contact();
		std::string	getName(void) const;
		std::string	getSurname(void) const;
		std::string	getNickname(void) const;
		std::string	getNumber(void) const;
		std::string getSecret(void) const;
		void		setName(std::string name);
		void		setSurname(std::string surname);
		void		setNickname(std::string nickname);
		void		setNumber(std::string number);
		void		setSecret(std::string secret);
};

#endif