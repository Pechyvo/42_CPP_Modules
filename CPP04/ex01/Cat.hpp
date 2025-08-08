#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
    private:
        Brain *brain;
        size_t thoughtIndex;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& other);
        void makeSound() const;
        
        // Brain access methods
        Brain* getBrain() const;
        void think(const std::string& idea);
        void displayThoughts(size_t start = 0, size_t end = 2) const;
};

#endif