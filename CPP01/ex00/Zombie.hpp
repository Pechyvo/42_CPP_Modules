#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Formatting.hpp"
#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce();
};

#endif