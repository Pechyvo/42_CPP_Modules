#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << GREEN << "Default Cat constructor called" << RESET << std::endl;
}

Cat::Cat(std::string name) : Animal(name) {
    this->type = "Cat";
    std::cout << GREEN << "Modified Cat constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
    }
    std::cout << GREEN << "Copy Cat constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

Cat::~Cat() {
    std::cout << RED << "Cat destructor called for " << U_RED << this->name << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << GREEN << "Copy Cat operator called for " << U_GREEN << this->name << RESET << std::endl;    

    return *this;
}

void Cat::makeSound() const {
    std::cout << CYAN << this->name + ": " << YELLOW << "* Meowing... *" << RESET << std::endl;
}
