#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Default Bureaucrat constructor called" << RESET <<std::endl;
#endif
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Modified Bureaucrat constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Copy Bureaucrat constructor called for " << U_GREEN << this->name << RESET << std::endl;
#endif
	if (this != &other) {
		this->grade = other.grade;
	}
}

Bureaucrat::~Bureaucrat() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] Bureaucrat destructor called for " << U_RED << this->name << RESET << std::endl;
#endif
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade(int n) {
	if (this->grade - n < 1)
		throw GradeTooHighException();
	this->grade -= n;
}

void Bureaucrat::decrementGrade(int n) {
	if (this->grade + n > 150)
		throw GradeTooLowException();
	this->grade += n;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureucrat grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureucrat grade is too low!";
}

void Bureaucrat::signForm(Form& form) {
	try {
        form.beSigned(*this);
        std::cout << U_GREEN << this->name << GREEN << " signed " << U_GREEN << form.getName() << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << U_RED << this->name << RED << " couldn't sign " << U_RED << form.getName() << RED << " because " << e.what() << RESET << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << U_CYAN << bureaucrat.getName() << CYAN << ", bureaucrat grade " << U_CYAN << bureaucrat.getGrade() << RESET;
	return os;
}
