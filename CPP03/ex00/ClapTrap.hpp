#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "../Formatting.hpp"
#include <iostream>
#include <string>

class ClapTrap {
    private:
        std::string type;
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
        unsigned int hpThreshold;
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif