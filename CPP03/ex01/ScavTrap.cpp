#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->name = "DefaultScav";
    this->type = "ScavTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->hpThreshold = this->hitPoints;
    std::cout << GREEN << "Default ScavTrap constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->type = "ScavTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->hpThreshold = this->hitPoints;
    std::cout << GREEN << "Modified ScavTrap constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    this->type = other.type;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->hpThreshold = other.hpThreshold;
    std::cout << GREEN << "Copy ScavTrap constructor called for " << U_GREEN << this->name << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << RED << "ScavTrap destructor called for " << U_RED << name << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
        this->hpThreshold = other.hpThreshold;
    }
    std::cout << GREEN << "Copy ScavTrap operator called for " << U_GREEN << this->name << RESET << std::endl;

    return *this;
}

void ScavTrap::guardGate(void) {
    std::cout << CYAN << "ScavTrap " << U_CYAN << this->name << CYAN << " is now in Gate keeper mode" << RESET << std::endl;
}
