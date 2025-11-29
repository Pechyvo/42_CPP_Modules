#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Default PresidentialPardonForm constructor called" << RESET <<std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Modified PresidentialPardonForm constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Copy PresidentialPardonForm constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

PresidentialPardonForm::~PresidentialPardonForm() {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] PresidentialPardonForm destructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

void PresidentialPardonForm::executeAction(const Bureaucrat& executor) const {
    (void)executor;
    
    std::cout << YELLOW << this->target << " has been pardoned by the Zaphod Beeblebrox." << RESET << std::endl;
}