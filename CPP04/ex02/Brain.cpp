#include "Brain.hpp"

Brain::Brain() {
    for (size_t i = 0; i < 100; i++) {
        this->ideas[i] = "no thoughts...";
    }
    std::cout << GREEN << "Default Brain constructor called" << RESET << std::endl;
}

Brain::Brain(std::string idea) {
    for (size_t i = 0; i < 100; i++) {
        this->ideas[i] = idea;
    }
    std::cout << GREEN << "Modified Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    std::cout << GREEN << "Copy Brain constructor called" << RESET << std::endl;
}

Brain::~Brain() {
    std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    std::cout << GREEN << "Copy Brain operator called" << RESET << std::endl;

    return *this;
}

// Getter method - returns idea at specific index
const std::string& Brain::getIdea(size_t index) const {
    if (index >= 100) {
        static const std::string error = "Index out of bounds";
        return error;
    }
    return this->ideas[index];
}

// Setter method - sets idea at specific index
void Brain::setIdea(size_t index, const std::string& idea) {
    if (index < 100) {
        this->ideas[index] = idea;
    }
}

// Display ideas from start to end (inclusive)
void Brain::displayIdeas(size_t start, size_t end) const {
    if (start >= 100) start = 99;
    if (end >= 100) end = 99;
    if (start > end) {
        size_t temp = start;
        start = end;
        end = temp;
    }
    
    std::cout << CYAN << "Brain ideas [" << start << "-" << end << "]:" << RESET << std::endl;
    for (size_t i = start; i <= end; i++) {
        std::cout << "  [" << i << "]: " << this->ideas[i] << std::endl;
    }
}
