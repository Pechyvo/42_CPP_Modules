#include "Intern.hpp"

Intern::Intern() {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Default Intern constructor called" << RESET << std::endl;
#endif
}

Intern::Intern(const Intern& other) {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Copy Intern constructor called" << RESET << std::endl;
#endif
    (void)other;
}

Intern::~Intern() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] Intern destructor called" << RESET << std::endl;
#endif
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            std::cout << GREEN << "[Intern] Created " << formName << " form." << RESET << std::endl;
            for (int j = 0; j < 3; ++j) {
                if (j != i) {
                    delete forms[j];
                }
            }
            return forms[i];
        }
    }
    
    for (int j = 0; j < 3; ++j) {
        delete forms[j];
    }
    std::cout << RED << "[Intern] Error: Unknown form type '" << formName << "'." << RESET << std::endl;
    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Unknown form type!";
}