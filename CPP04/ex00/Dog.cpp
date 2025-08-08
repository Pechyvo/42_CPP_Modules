#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << GREEN << "Default Dog constructor called" << RESET << std::endl;
}

Dog::Dog(std::string name) : Animal(name) {
    this->type = "Dog";
    std::cout << GREEN << "Modified Dog constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
    }
    std::cout << GREEN << "Copy Dog constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

Dog::~Dog() {
    std::cout << RED << "Dog destructor called for " << U_RED << this->name << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << GREEN << "Copy Dog operator called for " << U_GREEN << this->name << RESET << std::endl;

    return *this;
}

void Dog::makeSound() const {
    std::cout << CYAN << this->name + ": " << YELLOW << "* Barking... *" << RESET << std::endl;
}
