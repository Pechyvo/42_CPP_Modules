#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): weapon(weapon) {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] HumanA " << U_GREEN << name;
    std::cout << GREEN << " with weapon " << U_GREEN << weapon.getType();
    std::cout << GREEN << " constructor called" << RESET << std::endl;
#endif
    this->name = name;
}

HumanA::~HumanA() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] HumanA " << U_RED << this->name;
    std::cout << RED << " destructor called" << RESET << std::endl;
#endif
}

void HumanA::attack() {
    std::cout << BLUE << this->name << " attacks with their " << U_BLUE << this->weapon.getType() << RESET << std::endl;
}
