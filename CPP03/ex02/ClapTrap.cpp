#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : type("ClapTrap"), name("DefaultClap"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << GREEN << "Default ClapTrap constructor called" << RESET << std::endl;
    this->hpThreshold = this->hitPoints;
}

ClapTrap::ClapTrap(const std::string& name) : type("ClapTrap"), name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << GREEN << "Modified ClapTrap constructor called for " << U_GREEN << name << RESET << std::endl;
    this->hpThreshold = this->hitPoints;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    this->type = other.type;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->hpThreshold = other.hpThreshold;
    std::cout << GREEN << "Copy ClapTrap constructor called for " << U_GREEN << name << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << RED << "ClapTrap destructor called for " << U_RED << name << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
        this->hpThreshold = other.hpThreshold;
    }
    std::cout << GREEN << "Copy ClapTrap operator called for " << U_GREEN << name << RESET << std::endl;

    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints <= 0) {
        std::cout << RED << this->type + " " << U_RED << this->name << RED << " is dead and cannot attack!" << RESET << std::endl;
        return;
    }
    if (this->energyPoints > 0) {
        std::cout << CYAN << this->type + " " << U_CYAN << this->name << CYAN << " attacks " << U_CYAN << target << CYAN << ", causing " << U_CYAN << this->attackDamage << CYAN << " points of damage!" << RESET << std::endl;
        this->energyPoints--;
    } else {
        std::cout << YELLOW << this->type + " " << U_YELLOW << this->name << YELLOW << " has no energy left to attack!" << RESET << std::endl;
    }
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] ClapTrap " << U_PURPLE << this->name << PURPLE << " has " << U_PURPLE << this->energyPoints << PURPLE << " energy points remaining." << RESET << std::endl;
#endif
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount == 0) {
        std::cout << GREEN << this->type + " " << U_GREEN << this->name << GREEN << " avoided all damage!" << RESET << std::endl;
        return;
    }
    
    if (this->hitPoints == 0) {
        std::cout << RED << this->type + " " << U_RED << this->name << RED << " is already dead!" << RESET << std::endl;
        return;
    }
    
    if (this->hitPoints <= amount) {
        std::cout << RED << this->type + " " << U_RED << this->name << RED << " took " << U_RED << amount << RED << " damage and died!" << RESET << std::endl;
        this->hitPoints = 0;
    } else {
        this->hitPoints -= amount;
        std::cout << YELLOW << this->type + " " << U_YELLOW << this->name << YELLOW << " took " << U_YELLOW << amount << YELLOW << " damage, " << U_YELLOW << this->hitPoints << YELLOW << " hit points left." << RESET << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints == 0) {
        std::cout << YELLOW << this->type + " " << U_YELLOW << this->name << YELLOW << " has no energy left to repair!" << RESET << std::endl;
        return;
    }
    
    if (this->hitPoints == this->hpThreshold) {
        std::cout << GREEN << this->type + " " << U_GREEN << this->name << GREEN << " is already at full health!" << RESET << std::endl;
        return;
    }

    unsigned int newHitPoints = this->hitPoints + amount;
    if (newHitPoints > this->hpThreshold) {
        newHitPoints = this->hpThreshold;
#ifdef DEBUG
        std::cout << PURPLE << "[DEBUG] ClapTrap " << U_PURPLE << this->name << PURPLE << " hit points capped at " << U_PURPLE << this->hpThreshold << PURPLE << " after repair." << RESET << std::endl;
#endif
    }
    
    this->energyPoints--;
    this->hitPoints = newHitPoints;
    
    std::cout << BLUE << this->type + " " << U_BLUE << this->name << BLUE << " repaired " << U_BLUE << amount << BLUE << " hit points, " << U_BLUE << this->hitPoints << BLUE << " total hit points amount." << RESET << std::endl;
    
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] ClapTrap " << U_PURPLE << this->name << PURPLE << " has " << U_PURPLE << this->energyPoints << PURPLE << " energy points remaining." << RESET << std::endl;
#endif
}
