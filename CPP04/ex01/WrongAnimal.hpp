#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {
    protected:
        std::string type;
        std::string name;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        virtual ~WrongAnimal();
        WrongAnimal& operator= (const WrongAnimal& other);
        void makeSound() const;
        const std::string& getType() const;
};

#endif