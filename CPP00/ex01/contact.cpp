#include "contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getName(void) const
{
	return (this->name);
}

std::string Contact::getSurname(void) const
{
	return (this->surname);
}

std::string Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string Contact::getNumber(void) const
{
	return (this->number);
}

std::string Contact::getSecret(void) const
{
	return (this->secret);
}

void    Contact::setName(std::string name)
{
	this->name = name;
}

void    Contact::setSurname(std::string surname)
{
	this->surname = surname;
}

void    Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void    Contact::setNumber(std::string number)
{
	this->number = number;
}

void    Contact::setSecret(std::string secret)
{
	this->secret = secret;
}
