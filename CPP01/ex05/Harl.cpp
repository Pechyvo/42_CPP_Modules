#include "Harl.hpp"
#ifdef DEBUG
#include <cstdlib>
#include <ctime>
#endif

Harl::Harl() {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Harl constructor called" << RESET << std::endl;
#endif
}

Harl::~Harl() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] Harl destructor called" << RESET << std::endl;
#endif
}

enum Levels {
    LEVEL_DEBUG,
    LEVEL_INFO,
    LEVEL_WARNING,
    LEVEL_ERROR,
};

int getLevel(const std::string &level) {
    if (level == "DEBUG")
        return LEVEL_DEBUG;
    if (level == "INFO")
        return LEVEL_INFO;
    if (level == "WARNING")
        return LEVEL_WARNING;
    if (level == "ERROR")
        return LEVEL_ERROR;
#ifdef DEBUG
    if (level == "TEST") {
        std::cout << PURPLE << "[DEBUG] Random level requested" << RESET << std::endl;
        srand(time(0));
        int randomLevel = rand() % 4;
        std::cout << PURPLE << "[DEBUG] Random level selected: " << U_PURPLE << randomLevel << RESET << std::endl;
        return randomLevel;
    }
#endif
    return -1;
}

void Harl::complain(std::string level) {
    switch (getLevel(level)) {
        case LEVEL_DEBUG:
            this->debug();
            break;
        case LEVEL_INFO:
            this->info();
            break;
        case LEVEL_WARNING:
            this->warning();
            break;
        case LEVEL_ERROR:
            this->error();
            break;
        default:
            std::cout << RED << "ERROR » " << YELLOW << "Unknown argument" << RESET << std::endl;
            break;
    }
}

void Harl::debug() {
    std::cout << CYAN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << RESET << std::endl;
}

void Harl::info() {
    std::cout << BLUE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void Harl::warning() {
    std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << RESET << std::endl;
}

void Harl::error() {
    std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}