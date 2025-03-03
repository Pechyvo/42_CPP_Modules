#include "Zombie.hpp"

Zombie::Zombie() {
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG] Unknown Zombie constructor called" << RESET << std::endl;
#endif
}

Zombie::Zombie(std::string name) {
    this->name = name;
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG] " << this->name << " Zombie constructor called" << RESET << std::endl;
#endif
}

Zombie::~Zombie() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] " << this->name << ": destructor called" << RESET << std::endl;
#endif
}

void Zombie::announce() {
    std::cout << BLUE << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
