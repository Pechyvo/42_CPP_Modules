#include "Account.hpp"
#include "../Formatting.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
}

Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts;
    this->_nbWithdrawals = 0;
    this->_nbDeposits = 0;
    this->_amount = initial_deposit;
    this->_totalAmount += initial_deposit;
    this->_nbAccounts++;
    _displayTimestamp();
    std::cout << BLUE << "index" << GREEN << ":" << _accountIndex << ";";
    std::cout << BLUE << "amount" GREEN":" << _amount << ";";
    std::cout << RESET << "created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << BLUE << "index" << GREEN << ":" << _accountIndex << ";";
    std::cout << BLUE << "amount" << GREEN << ":" << _amount << ";";
    std::cout << RESET << "closed" << std::endl;
}

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::_displayTimestamp(void) {
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    char buffer[20];

    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
    std::cout << YELLOW << "[" << GREEN << buffer << YELLOW << "] " << RESET;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << BLUE << "accounts" << GREEN << ":" << _nbAccounts << ";";
    std::cout << BLUE << "total" << GREEN << ":" << _totalAmount << ";";
    std::cout << BLUE << "deposits" << GREEN << ":" << _totalNbDeposits << ";";
    std::cout << BLUE << "withdrawals" << GREEN << ":" << _totalNbWithdrawals;
    std::cout << std::endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << BLUE << "index" << GREEN << ":" << _accountIndex << ";";
    std::cout << BLUE << "amount" << GREEN << ":" << _amount << ";";
    std::cout << BLUE << "deposits" << GREEN << ":" << _nbDeposits << ";";
    std::cout << BLUE << "withdrawals" << GREEN << ":" << _nbWithdrawals;
    std::cout << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << BLUE << "index" << GREEN << ":" << _accountIndex << ";";
    std::cout << BLUE << "p_amount" << GREEN << ":" << _amount << ";";
    std::cout << BLUE << "deposit" << GREEN << ":" << deposit << ";";
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << BLUE << "amount" << GREEN << ":" << _amount << ";";
    std::cout << BLUE << "nb_deposits" << GREEN << ":" << _nbDeposits;
    std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << BLUE << "index" << GREEN << ":" << _accountIndex << ";";
    std::cout << BLUE << "p_amount" << GREEN << ":" << _amount << ";";
    std::cout << BLUE << "withdrawal" << GREEN << ":";
    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        std::cout << withdrawal << ";";
        std::cout << BLUE << "amount" << GREEN << ":" << _amount << ";";
        std::cout << BLUE << "nb_withdrawals" << GREEN << ":" << _nbWithdrawals << std::endl;
        return true;
    }
    std::cout << "refused" << std::endl;
    return false;
}
