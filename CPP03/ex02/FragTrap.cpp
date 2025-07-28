#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << GREEN << "Default FragTrap constructor called" << RESET << std::endl;
    this->name = "DefaultFrag";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->hpThreshold = this->hitPoints;
    this->type = "FragTrap";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << GREEN << "Modified FragTrap constructor called for " << U_GREEN << name << RESET << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->hpThreshold = this->hitPoints;
    this->type = "FragTrap";
}

FragTrap::~FragTrap() {
    std::cout << RED << "FragTrap destructor called for " << U_RED << name << RESET << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << CYAN << "FragTrap " << U_CYAN << this->name << CYAN << " is requesting high fives!" << RESET << std::endl;
}
