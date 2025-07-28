#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include "../Formatting.hpp"
#include <iostream>
#include <string>
#include <cmath>

class Fixed {
    private:
        int val;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int val);
        Fixed(const float val);
        ~Fixed();
        Fixed& operator=(const Fixed& other);
        bool operator>(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif