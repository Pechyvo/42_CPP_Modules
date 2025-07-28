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
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif