#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] HumanB " << U_GREEN << name;
    std::cout << GREEN << " constructor called" << RESET << std::endl;
#endif
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] HumanB " << U_RED << this->name;
    std::cout << RED << " destructor called" << RESET << std::endl;
#endif
}

void HumanB::setWeapon(Weapon& weapon) {
#ifdef DEBUG
    std::cout << YELLOW << "[DEBUG] HumanB " << U_YELLOW << this->name;
    std::cout << YELLOW << " weapon changed to " << U_YELLOW << weapon.getType() << RESET << std::endl;
#endif
    this->weapon = &weapon;
}

void HumanB::attack() {
    if (!this->weapon)
        std::cout << CYAN << this->name << " attacks with " << U_CYAN << "their fists" << RESET << std::endl;
    else
        std::cout << CYAN << this->name << " attacks with their " << U_CYAN << this->weapon->getType() << RESET << std::endl;
}

