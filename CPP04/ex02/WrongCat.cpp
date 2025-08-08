#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << GREEN << "Default WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name) {
    this->type = "WrongCat";
    std::cout << GREEN << "Modified WrongCat constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    this->type = other.type;
    this->name = other.name;
    std::cout << GREEN << "Copy WrongCat constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

WrongCat::~WrongCat() {
    // WrongAnimal::~WrongAnimal();
    std::cout << RED << "WrongCat destructor called for " << U_RED << this->name << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << GREEN << "Copy WrongCat operator called for " << U_GREEN << this->name << RESET << std::endl;    

    return *this;
}

void WrongCat::makeSound() const {
    std::cout << CYAN << this->name + ": " << YELLOW << "* Meowing... *" << RESET << std::endl;
}
