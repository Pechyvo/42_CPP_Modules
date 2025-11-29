#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradetoSign(125), gradetoExec(125) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Default AForm constructor called" << RESET <<std::endl;
#endif
}

AForm::AForm(const std::string name, const int toSign, const int toExec) : name(name), isSigned(false), gradetoSign(toSign), gradetoExec(toExec) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Modified AForm constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
	if (toSign < 1 || toExec < 1) {
        throw GradeTooHighException();
    } else if (toSign > 150 || toExec > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) : name(other.name), gradetoSign(other.gradetoSign), gradetoExec(other.gradetoExec){
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Copy AForm constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
}

AForm::~AForm() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] AForm destructor called for " << U_RED << this->name << RESET << std::endl;
#endif
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

std::string AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradetoSign() const {
	return this->gradetoSign;
}

int AForm::getGradetoExecute() const {
	return this->gradetoExec;
}

void AForm::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > this->gradetoSign) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->gradetoExec) {
		throw GradeTooLowException();
	}
	executeAction(executor);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

const char* AForm::AlreadySignedException::what() const throw() {
	return "Form is already signed!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &i) {
	std::string signedStatus = i.getIsSigned() ? "true" : "false";
	os << U_CYAN << i.getName() << CYAN << ", AForm grade to sign " << U_CYAN << i.getGradetoSign() << CYAN << ", grade to execute " << U_CYAN << i.getGradetoExecute() << CYAN << " and AForm is signed: " << U_CYAN  << signedStatus << CYAN  << "." << RESET;
	return os;
}
