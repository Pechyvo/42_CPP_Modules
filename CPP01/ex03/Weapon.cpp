#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Weapon " << U_GREEN << type;
    std::cout << GREEN << " constructor called" << RESET << std::endl;
#endif
    this->type = type;
}

Weapon::~Weapon() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] Weapon " << U_RED << this->type;
    std::cout << RED <<  " destructor called" << RESET << std::endl;
#endif
}

std::string Weapon::getType() const {
    return this->type;
}

void Weapon::setType(std::string type) {
#ifdef DEBUG
    std::cout << YELLOW << "[DEBUG] Weapon " << U_YELLOW << this->type;
    std::cout << YELLOW << " type changed to " << U_YELLOW << type << RESET << std::endl;
#endif
    this->type = type;
}
