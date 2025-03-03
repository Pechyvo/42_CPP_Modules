#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "../Formatting.hpp"
#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string type);
        ~Weapon();
        std::string getType() const;
        void        setType(std::string type);
};

#endif