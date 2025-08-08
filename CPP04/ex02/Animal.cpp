#include "Animal.hpp"

Animal::Animal() : type("Animal"), name("Random Animal") {
    std::cout << GREEN << "Default Animal constructor called" << RESET << std::endl;
}

Animal::Animal(std::string name) : type("Animal"), name(name) {
    std::cout << GREEN << "Modified Animal constructor called for " << U_GREEN << name << RESET << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type), name(other.name) {
    std::cout << GREEN << "Copy Animal constructor called for " << U_GREEN << name << RESET << std::endl;
}

Animal::~Animal() {
    std::cout << RED << "Animal destructor called for " << U_RED << name << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
    }
    std::cout << GREEN << "Copy Animal operator called for " << U_GREEN << name << RESET << std::endl;

    return *this;
}

void Animal::makeSound() const {
    std::cout << CYAN << this->type + ": " << YELLOW << "* Animal sounds... *" << std::endl;
}

const std::string& Animal::getType() const {
    return this->type;
}
