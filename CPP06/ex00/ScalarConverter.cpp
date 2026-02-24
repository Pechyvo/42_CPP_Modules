#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
#ifdef DEBUG
	std::cout <<  GREEN << "[DEBUG] Default ScalarConverter constructor called" << RESET <<std::endl;
#endif
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
#ifdef DEBUG
    std::cout <<  GREEN << "[DEBUG] Copy ScalarConverter constructor called" << RESET <<std::endl;
#endif
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
#ifdef DEBUG
    std::cout <<  GREEN << "[DEBUG] Copy ScalarConverter assignment operator called" << RESET <<std::endl;
#endif
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] ScalarConverter destructor called" << RESET <<std::endl;
#endif
}

void ScalarConverter::convert(const std::string& literal) {
    
}
