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

void ScalarConverter::printChar(double d) {
    std::cout << BLUE << "char: " << RESET;
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
        std::cout << RED << "impossible" << RESET << std::endl;
    } else if (!std::isprint(static_cast<char>(d))) {
        std::cout << PURPLE << "Non displayable" << RESET << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double d) {
    std::cout << YELLOW << "int: " << RESET;
    if (std::isnan(d) || std::isinf(d) ||
        d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << RED << "impossible" << RESET << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }
}

void ScalarConverter::printFloat(double d) {
    std::cout << GREEN << "float: " << RESET;
    if (std::isnan(d) || std::isinf(d)) {
        std::cout << RED << "impossible" << RESET << std::endl;
    } else {
        std::cout << static_cast<float>(d);
        double intPart;
        if (std::modf(d, &intPart) == 0.0 && !std::isinf(d)) {
            std::cout << ".0";
        }
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d) {
    std::cout << CYAN << "double: " << RESET;
    if (std::isnan(d) || std::isinf(d)) {
        std::cout << RED << "impossible" << RESET << std::endl;
    } else {
        std::cout << d;
        double intPart;
        if (std::modf(d, &intPart) == 0.0 && !std::isinf(d)) {
            std::cout << ".0";
        }
        std::cout << std::endl;
    }
}

void ScalarConverter::printError() {
    std::cout << BLUE << "char: " << RED << "impossible" << RESET << std::endl;
    std::cout << YELLOW << "int: " << RED << "impossible" << RESET << std::endl;
    std::cout << GREEN << "float: " << RED << "impossible" << RESET << std::endl;
    std::cout << CYAN << "double: " << RED << "impossible" << RESET << std::endl;
}

void ScalarConverter::catchImpossible(const std::string& literal) {
    if (literal.empty()) {
        printError();
        throw std::runtime_error("Empty literal");
    }

    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << BLUE << "char: " << RESET << "'" << c << "'" << std::endl;
        std::cout << YELLOW << "int: " << RESET << static_cast<int>(c) << std::endl;
        std::cout << GREEN << "float: " << RESET << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << CYAN << "double: " << RESET << static_cast<double>(c) << ".0" << std::endl;
        throw std::runtime_error("Single char literal");
    }

    char* pEnd = NULL;
    double d = std::strtod(literal.c_str(), &pEnd);
    std::string endStr(pEnd);
    
    if (endStr != "" && endStr != "f") {
        printError();
        throw std::runtime_error("Invalid characters in literal");
    }

    if (d == 0.0 && literal[0] != '0' && literal[0] != '+' && literal[0] != '-') {
        printError();
        throw std::runtime_error("Failed to parse number");
    }
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        catchImpossible(literal);

        char* pEnd = NULL;
        double d = std::strtod(literal.c_str(), &pEnd);

        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
    } catch(std::exception& e) {
        return ;
    }
}
