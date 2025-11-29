#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Default RobotomyRequestForm constructor called" << RESET <<std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Modified RobotomyRequestForm constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Copy RobotomyRequestForm constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

RobotomyRequestForm::~RobotomyRequestForm() {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] RobotomyRequestForm destructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->target;
}

void RobotomyRequestForm::executeAction(const Bureaucrat& executor) const {
    (void)executor;
    
    std::cout << YELLOW << "*DRILLING NOISES* BZZZZZZT! WHIRRRR! CLANK CLANK!" << RESET << std::endl;
    
    srand(time(NULL));
    
    if (rand() % 2 == 0) {
        std::cout << U_GREEN << this->target << GREEN << " has been robotomized successfully!" << RESET << std::endl;
    } else {
        std::cout << U_RED << "Robotomy failed on " << this->target << "!" << RESET << std::endl;
    }
}