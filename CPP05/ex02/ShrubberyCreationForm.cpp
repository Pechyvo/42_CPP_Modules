#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Default ShrubberyCreationForm constructor called" << RESET <<std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Modified ShrubberyCreationForm constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Copy ShrubberyCreationForm constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] ShrubberyCreationForm destructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->target;
}

void ShrubberyCreationForm::executeAction(const Bureaucrat& executor) const {
    (void)executor;
    
    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not create file");
    }
    
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
    
    file.close();
    std::cout << GREEN << "Created shrubbery file: " << U_GREEN << filename << RESET << std::endl;
}