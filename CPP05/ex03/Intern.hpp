#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);
        AForm* makeForm(const std::string& formName, const std::string& target) const;
        
        class UnknownFormException : public std::exception {
            public:
            virtual const char* what() const throw();
        };
};

#endif