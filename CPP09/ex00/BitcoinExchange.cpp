#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& inputFile) : _dbFile("data.csv"), _inpuFile(inputFile) {
    if (isInputValid())
        execute();
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isInputValid() {
    std::string line;
    std::fstream f(this->_dbFile.c_str());

    if (!f.is_open())
        throw BitcoinExchangeFileNotOpenException();

    getline(f, line);
    if (line != "date,exchange_rate") {
        std::cerr << RED << "Corrupted db file -> missing \"date,exchange_rate\"" << RESET << std::endl;
        return false;
    }

    while (getline(f, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            std::cerr << RED << "Wrong data format" << RESET << std::endl;
        std::string date = line.substr(0, pos);
        std::string num = line.substr(pos + 1);
        if (this->isValidDate(date) && this->isValidNum(num)) {
            double val = std::atof(num.c_str());
            this->_db[date] = val;
        } else
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidDate(std::string date) {
    return true;
}

bool BitcoinExchange::isValidDateFormat(std::string date) {
    return true;
}

bool BitcoinExchange::isValidNum(std::string num) {
    return true;
}

void BitcoinExchange::execute() {
    std::string line;
}
