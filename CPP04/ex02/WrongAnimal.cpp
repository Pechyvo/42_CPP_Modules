#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"), name("Random WrongAnimal") {
    std::cout << GREEN << "Default WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type("WrongAnimal"), name(name) {
    std::cout << GREEN << "Modified WrongAnimal constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type), name(other.name) {
    std::cout << GREEN << "Copy WrongAnimal constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << RED << "WrongAnimal destructor called for " << U_RED << this->name << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
    }
    std::cout << GREEN << "Copy WrongAnimal operator called for " << U_GREEN << this->name << RESET << std::endl;

    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << CYAN << this->name + ": " << YELLOW << "* WrongAnimal sounds... *" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return this->type;
}

