#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
    private:
        Brain* brain;
        size_t thoughtIndex;
    public:
        Dog();
        Dog(std::string name);
        Dog(const Dog& other);
        ~Dog();
        Dog& operator=(const Dog& other);
        void makeSound() const;
        
        // Brain access methods
        Brain* getBrain() const;
        void think(const std::string& idea);
        void displayThoughts(size_t start = 0, size_t end = 2) const;
};

#endif