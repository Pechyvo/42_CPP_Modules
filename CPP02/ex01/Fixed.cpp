#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
    this->val = 0;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
    this->val = other.val;
}

Fixed::Fixed(const int val) {
    std::cout << GREEN << "Int constructor called" << RESET << std::endl;
    this->val = val * (1 << bits);
}

Fixed::Fixed(const float val) {
    std::cout << GREEN << "Float constructor called" << RESET << std::endl;
    this->val = roundf(val * (1 << bits));
}

Fixed::~Fixed() {
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << CYAN << "Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        this->val = other.val;
    }
    
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << CYAN << "getRawBits member function called" << RESET << std::endl;
    return this->val;
}

void Fixed::setRawBits(int const raw) {
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG] setRawBits called with value: " << raw << RESET << std::endl;
#endif
    this->val = raw;
}

int Fixed::toInt(void) const {
    return this->val / (1 << bits);
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->val) / (1 << bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
    return os << other.toFloat();
}
