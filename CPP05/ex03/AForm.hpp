#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "../Formatting.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradetoSign;
        const int gradetoExec;
    protected:
        virtual void executeAction(Bureaucrat const & executor) const = 0;
    public:
        AForm();
        AForm(const std::string name, const int gradetoSign, const int gradetoExec);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator = (const AForm& other);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradetoSign() const;
        int getGradetoExecute() const;
        void beSigned(const Bureaucrat& bur);
        virtual void execute(Bureaucrat const & executor) const;

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
        class FormNotSignedException : public std::exception {
            public:
            virtual const char* what() const throw();
        };
};

std::ostream &operator <<(std::ostream &os, const AForm &i);

#endif