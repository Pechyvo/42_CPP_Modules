#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "../Formatting.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int gradetoSign;
        const int gradetoExec;
    public:
        Form();
        Form(const std::string name, const int gradetoSign, const int gradetoExec);
        Form(const Form& other);
        ~Form();
        Form& operator = (const Form& other);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradetoSign() const;
        int getGradetoExecute() const;
        void beSigned(const Bureaucrat& bur);
        
        class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
        class AlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator <<(std::ostream &os, const Form &i);

#endif