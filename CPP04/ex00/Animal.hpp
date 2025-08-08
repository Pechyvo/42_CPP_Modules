#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "../Formatting.hpp"
#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal() {}
        virtual void makeSound() const = 0;
};

#endif