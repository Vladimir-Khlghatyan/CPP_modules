#include "Account.hpp"

int	Account::_accountIndex;
int	Account::_amount;
int	Account::_nbDeposits;
int	Account::_nbWithdrawals;

int	getNbAccounts(void)
{
	return (this->_nbAccounts);
}

int	getTotalAmount(void)
{
	return (this->_totalAmount);
}

int	getNbDeposits(void)
{
	return (this->_totalNbDeposits);
}

int	getNbWithdrawals(void)
{
	return (this->_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
    time_t  now = time(&now);
    tm      *lt = localtime(&now);

    std::cout << "[" << lt->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << lt->tm_sec << "] \n";
    return (0);
}

Account::Account(int initial_deposit)
{
	_nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    this->_displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
    _nbAccounts++;

    this->_displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";closed\n";
}


