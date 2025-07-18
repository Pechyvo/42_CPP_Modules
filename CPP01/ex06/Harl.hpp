#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include "../Formatting.hpp"
#include <iostream>
#include <string>

class Harl {
    private:
        void debug();
        void info();
        void warning();
        void error();
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
        void harlFilter(std::string level);
};

#endif