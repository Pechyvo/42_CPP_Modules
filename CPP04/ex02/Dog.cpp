#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain("Dog thoughts")), thoughtIndex(0) {
    this->type = "Dog";
    std::cout << GREEN << "Default Dog constructor called" << RESET << std::endl;
}

Dog::Dog(std::string name) : Animal(name), brain(new Brain("Dog thoughts")), thoughtIndex(0) {
    this->type = "Dog";
    std::cout << GREEN << "Modified Dog constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
        this->brain = new Brain(*other.brain);
        this->thoughtIndex = other.thoughtIndex;
    }
    std::cout << GREEN << "Copy Dog constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << RED << "Dog destructor called for " << U_RED << this->name << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
        this->thoughtIndex = other.thoughtIndex;
    }
    std::cout << GREEN << "Copy Dog operator called for " << U_GREEN << this->name << RESET << std::endl;

    return *this;
}

void Dog::makeSound() const {
    std::cout << CYAN << this->name + ": " << YELLOW << "* Barking... *" << RESET << std::endl;
}

/* Brain access methods */

// Return pointer to brain (for direct access if needed)
Brain* Dog::getBrain() const {
    return this->brain;
}

// Add a new thought to the brain
void Dog::think(const std::string& idea) {
    this->brain->setIdea(this->thoughtIndex % 100, idea);
    this->thoughtIndex++;
    std::cout << CYAN << this->name << " thinks: " << YELLOW << idea << RESET << std::endl;
}

// Display some of the dog's thoughts in a specific range
void Dog::displayThoughts(size_t start, size_t end) const {
    std::cout << CYAN << this->name << "'s thoughts:" << RESET << std::endl;
    this->brain->displayIdeas(start, end);
}


