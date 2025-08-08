#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->name = "DefaultFrag";
    this->type = "FragTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->hpThreshold = this->hitPoints;
    std::cout << GREEN << "Default FragTrap constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->type = "FragTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->hpThreshold = this->hitPoints;
    std::cout << GREEN << "Modified FragTrap constructor called for " << U_GREEN << name << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    this->type = other.type;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->hpThreshold = other.hpThreshold;
    std::cout << GREEN << "Copy FragTrap constructor called for " << U_GREEN << name << RESET << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << RED << "FragTrap destructor called for " << U_RED << name << RESET << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
        this->hpThreshold = other.hpThreshold;
    }
    std::cout << GREEN << "Copy FragTrap operator called for " << U_GREEN << name << RESET << std::endl;

    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << CYAN << "FragTrap " << U_CYAN << this->name << CYAN << " is requesting high fives!" << RESET << std::endl;
}
