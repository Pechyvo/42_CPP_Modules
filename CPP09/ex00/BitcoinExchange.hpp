#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "../Formatting.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

enum validation_flag {
    INPUT,
    DATA,
};

enum date_flag {
    YEAR,
    MONTH,
    DAY,
};

class BitcoinExchange {
    private:
        std::map<std::string, double> _db;
        const std::string _dbFile;
        const std::string _inpuFile;
        bool isInputValid();
        bool isValidDate(std::string date);
        bool isValidDateFormat(std::string date);
        bool isValidNum(std::string num, validation_flag flag);
        void execute();
    public:
        BitcoinExchange(const std::string& inputFile);
        ~BitcoinExchange();
        
        class BitcoinExchangeFileNotOpenException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Could not open db file";
                }
        };
};

#endif