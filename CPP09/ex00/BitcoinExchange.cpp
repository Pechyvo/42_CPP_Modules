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
        std::cerr << RED << "Error: corrupted db file => missing \"date,exchange_rate\"" << RESET << std::endl;
        return false;
    }

    while (getline(f, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
        std::string date = line.substr(0, pos);
        std::string num = line.substr(pos + 1);
        if (this->isValidDate(date) && this->isValidNum(num, DATA)) {
            double val = std::atof(num.c_str());
            this->_db[date] = val;
        } else
            return false;
    }

    return true;
}

namespace {
    bool isLeapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    int getMonthMaxDay(int year, int month) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 0;
        }
    }
}

bool BitcoinExchange::isValidDate(std::string date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
        return false;
    }

    std::string parts[3] = { date.substr(0, 4), date.substr(5, 2), date.substr(8, 2) };

    for (int i = YEAR; i <= DAY; ++i) {
        if (!this->isValidDateFormat(parts[i])) {
            std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
            return false;
        }
    }

    int nums[3] = { std::atoi(parts[YEAR].c_str()), std::atoi(parts[MONTH].c_str()), std::atoi(parts[DAY].c_str()) };
    const int maxDay = getMonthMaxDay(nums[YEAR], nums[MONTH]);

    for (int i = YEAR; i <= DAY; ++i) {
        bool valid;
        switch (i) {
            case YEAR:  valid = (nums[YEAR] >= 2009 && nums[YEAR] <= 2025);  break;
            case MONTH: valid = (nums[MONTH] >= 1 && nums[MONTH] <= 12);     break;
            case DAY:   valid = (nums[DAY] >= 1 && nums[DAY] <= maxDay);     break;
            default:    valid = true;
        }
        if (!valid) {
            std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
            return false;
        }
    }

    return true;
}

bool BitcoinExchange::isValidDateFormat(std::string date) {
    for (std::string::iterator it = date.begin(); it != date.end(); ++it) {
        if (!std::isdigit(static_cast<unsigned char>(*it)))
            return false;
    }
    return true;
}

bool BitcoinExchange::isValidNum(std::string num, validation_flag flag) {
    if (num.empty()) {
        std::cerr << RED << "Error: bad input." << RESET << std::endl;
        return false;
    }

    bool hasDot = false;
    size_t afterDot = 0;
    char* pEnd;
    double res = std::strtod(num.c_str(), &pEnd);

    for (std::string::iterator it = num.begin(); it != num.end(); ++it) {
        if (*it == '.') {
            if (hasDot || it == num.begin() || it + 1 == num.end()) {
                std::cerr << RED << "Error: bad input." << RESET << std::endl;
                return false;
            }
            hasDot = true;
        } else if (!std::isdigit(static_cast<unsigned char>(*it))) {
            std::cerr << RED << "Error: bad input." << RESET << std::endl;
            return false;
        } else if (hasDot) {
            afterDot++;
        }
    }

    if (*pEnd != '\0' || res < 0) {
        std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
        return false;
    }

    switch (flag) {
        case DATA:
            if (hasDot && afterDot > 2) {
                std::cerr << RED << "Error: bad input." << RESET << std::endl;
                return false;
            }
            break;
        case INPUT:
            if (res > 1000) {
                std::cerr << RED << "Error: too large a number." << RESET << std::endl;
                return false;
            }
            break;
    }

    return true;
}

void BitcoinExchange::execute() {
    std::string line;
    std::fstream f(this->_inpuFile.c_str());

    if (!f.is_open())
        throw BitcoinExchangeFileNotOpenException();

    getline(f, line); // to skip header line
    while (getline(f, line)) {
        size_t pos = line.find('|');
        if (pos == std::string::npos) {
            std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string num  = line.substr(pos + 1);

        while (!date.empty() && std::isspace(static_cast<unsigned char>(date[date.size() - 1])))
            date.erase(date.size() - 1);
        while (!num.empty() && std::isspace(static_cast<unsigned char>(num[0])))
            num.erase(0, 1);

        if (!this->isValidDate(date) || !this->isValidNum(num, INPUT))
            continue;

        double value = std::atof(num.c_str());
        std::map<std::string, double>::iterator it = _db.find(date);
        if (it == this->_db.end()) {
            it = this->_db.lower_bound(date);
            if (it == this->_db.begin()) {
                std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
}
