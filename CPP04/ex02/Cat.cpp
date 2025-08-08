#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain("Cat thoughts")), thoughtIndex(0) {
    this->type = "Cat";
    std::cout << GREEN << "Default Cat constructor called" << RESET << std::endl;
}

Cat::Cat(std::string name) : Animal(name), brain(new Brain("Cat thoughts")), thoughtIndex(0) {
    this->type = "Cat";
    std::cout << GREEN << "Modified Cat constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
        this->brain = new Brain(*other.brain);
        this->thoughtIndex = other.thoughtIndex;  // Copy the thought index
    }
    std::cout << GREEN << "Copy Cat constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << RED << "Cat destructor called for " << U_RED << this->name << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
        this->thoughtIndex = other.thoughtIndex;  // Copy the thought index
    }
    std::cout << GREEN << "Copy Cat operator called for " << U_GREEN << this->name << RESET << std::endl;    

    return *this;
}

void Cat::makeSound() const {
    std::cout << CYAN << this->name + ": " << YELLOW << "* Meowing... *" << RESET << std::endl;
}

/* Brain access methods */

// Return pointer to brain (for direct access if needed)
Brain* Cat::getBrain() const {
    return this->brain;
}

// Add a new thought to the brain
void Cat::think(const std::string& idea) {
    this->brain->setIdea(this->thoughtIndex % 100, idea);
    this->thoughtIndex++;
    std::cout << CYAN << this->name << " thinks: " << YELLOW << idea << RESET << std::endl;
}

// Display some of the cat's thoughts in a specific range
void Cat::displayThoughts(size_t start, size_t end) const {
    std::cout << CYAN << this->name << "'s thoughts:" << RESET << std::endl;
    this->brain->displayIdeas(start, end);
}


