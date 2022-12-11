#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ⬆ removeing the "static" keyword
// because: https://stackoverflow.com/questions/15725922/static-function-a-storage-class-may-not-be-specified-here

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
    time_t  now;
    tm      *lt;
 
    time(&now);
    lt = std::localtime(&now);
    std::cout << "[" << lt->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_sec << "] ";
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_nbAccounts++;
    this->_accountIndex = this->_nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_totalAmount += this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    this->_displayTimestamp();

    std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
    this->_nbAccounts--;

    this->_displayTimestamp();

    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";closed" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";" <<std::flush;
    this->_amount += deposit;
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";" << std::flush;
    this->_nbDeposits++;
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

bool    Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:" << std::flush;
    if (withdrawal > this->checkAmount())
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout << withdrawal << ";" << std::flush;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

void    Account::displayStatus(void) const
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}


