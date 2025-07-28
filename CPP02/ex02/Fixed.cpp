#include "Fixed.hpp"

Fixed::Fixed() {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Default constructor called" << RESET << std::endl;
#endif
    this->val = 0;
}

Fixed::Fixed(const Fixed& other) {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Copy constructor called" << RESET << std::endl;
#endif
    this->val = other.val;
}

Fixed::Fixed(const int val) {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Int constructor called" << RESET << std::endl;
#endif
    this->val = val * (1 << bits);
}

Fixed::Fixed(const float val) {
#ifdef DEBUG
    std::cout << GREEN << "[DEBUG] Float constructor called" << RESET << std::endl;
#endif
    this->val = roundf(val * (1 << bits));
}

Fixed::~Fixed() {
#ifdef DEBUG
    std::cout << RED << "[DEBUG] Destructor called" << RESET << std::endl;
#endif
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->val = other.val;
    }
    
    return *this;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->val > other.val;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->val < other.val;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->val >= other.val;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->val <= other.val;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->val == other.val;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->val != other.val;
}

Fixed Fixed::operator+(const Fixed& other) {
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG] Tmp constructor called --> " << RESET;
#endif
    Fixed tmp;
    tmp.val = this->val + other.val;
    return tmp;
}

Fixed Fixed::operator-(const Fixed& other) {
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG] Tmp constructor called --> " << RESET;
#endif
    Fixed tmp;
    tmp.val = this->val - other.val;
    return tmp;
}

Fixed Fixed::operator*(const Fixed& other) {
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG] Tmp constructor called --> " << RESET;
#endif
    Fixed tmp;
    tmp.val = (this->val * other.val) / (1 << bits);
    return tmp;
}

Fixed Fixed::operator/(const Fixed& other) {
    if (other.val == 0) {
        throw std::runtime_error("Division by zero");
    }
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG] Tmp constructor called --> " << RESET;
#endif
    Fixed tmp;
    tmp.val = (this->val * (1 << bits)) / other.val;
    return tmp;
}

Fixed& Fixed::operator++() {
    this->val++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->val++;
    return tmp;
}

Fixed& Fixed::operator--() {
    this->val--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->val--;
    return tmp;
}

int Fixed::getRawBits(void) const {
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

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
    return os << other.toFloat();
}
