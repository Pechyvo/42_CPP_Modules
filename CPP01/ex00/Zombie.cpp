#include "Zombie.hpp"

Zombie::Zombie() {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Unknown Zombie constructor called" << RESET << std::endl;
#endif
}

Zombie::Zombie(std::string name) {
    this->name = name;
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] " << U_GREEN << this->name << GREEN << " constructor called" << RESET << std::endl;
#endif
}

Zombie::~Zombie() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] " << U_RED << this->name << RED << " destructor called" << RESET << std::endl;
#endif
}

void Zombie::announce() {
    std::cout << YELLOW << this->name + ": " << BLUE << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
