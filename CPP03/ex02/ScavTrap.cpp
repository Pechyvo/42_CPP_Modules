#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << GREEN << "Default ScavTrap constructor called" << RESET << std::endl;
    this->name = "DefaultScav";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->hpThreshold = this->hitPoints;
    this->type = "ScavTrap";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << GREEN << "Modified ScavTrap constructor called for " << U_GREEN << name << RESET << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->hpThreshold = this->hitPoints;
    this->type = "ScavTrap";
}

ScavTrap::~ScavTrap() {
    std::cout << RED << "ScavTrap destructor called for " << U_RED << name << RESET << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << CYAN << "ScavTrap " << U_CYAN << this->name << CYAN << " is now in Gate keeper mode" << RESET << std::endl;
}
