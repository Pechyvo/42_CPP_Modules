#pragma once
#ifndef TYPE_HPP
#define TYPE_HPP
#include "../Formatting.hpp"
#include "Extra.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

class Type {
    private:
        Type();
    public:
        static Base* generate(void);
        static void indentify(Base* p);
        static void indentify(Base& p);
};

#endif