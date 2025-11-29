#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradetoSign(125), gradetoExec(125) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Default Form constructor called" << RESET <<std::endl;
#endif
}

Form::Form(const std::string name, const int toSign, const int toExec) : name(name), isSigned(false), gradetoSign(toSign), gradetoExec(toExec) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Modified Form constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
	if (toSign < 1 || toExec < 1) {
        throw GradeTooHighException();
    } else if (toSign > 150 || toExec > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other) : name(other.name), gradetoSign(other.gradetoSign), gradetoExec(other.gradetoExec){
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Copy Form constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
}

Form::~Form() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] Form destructor called for " << U_RED << this->name << RESET << std::endl;
#endif
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

std::string Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradetoSign() const {
	return this->gradetoSign;
}

int Form::getGradetoExecute() const {
	return this->gradetoExec;
}

void Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > this->gradetoSign) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "Form is already signed!";
}

std::ostream &operator<<(std::ostream &os, const Form &i) {
	std::string signedStatus = i.getIsSigned() ? "true" : "false";
	os << U_CYAN << i.getName() << CYAN << ", form grade to sign " << U_CYAN << i.getGradetoSign() << CYAN << ", grade to execute " << U_CYAN << i.getGradetoExecute() << CYAN << " and form is signed: " << U_CYAN  << signedStatus << CYAN  << "." << RESET;
	return os;
}
