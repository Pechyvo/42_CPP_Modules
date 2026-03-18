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
		std::string _dbFile;
		std::string _inpuFile;
		bool isInputValid();
		bool isValidDate(std::string date);
		bool isValidDateFormat(std::string date);
		bool isValidNum(std::string num, validation_flag flag);
		void execute();
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& inputFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		
		class BitcoinExchangeFileNotOpenException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: could not open db file";
				}
		};
};

#endif