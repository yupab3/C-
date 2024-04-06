#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;

Account::Account(void)
{
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	_amount = 0;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	_amount = initial_deposit;
	Account::_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
	// [19920104_091532] index:0;amount:47;closed
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	time_t		EpochTime;
	struct tm*	Local_Time;

	EpochTime = time(NULL);
	Local_Time = localtime(&EpochTime);

	std::cout << '[' << \
				Local_Time->tm_year + 1900 << \
				std::setw(2) << std::setfill('0') << Local_Time->tm_mon + 1 << \
				std::setw(2) << std::setfill('0') << Local_Time->tm_mday << '_' << \
				std::setw(2) << std::setfill('0') << Local_Time->tm_hour << \
				std::setw(2) << std::setfill('0') << Local_Time->tm_min << \
				std::setw(2) << std::setfill('0') << Local_Time->tm_sec << \
				"] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << \
				";total:" << Account::_totalAmount << \
				";deposits:" << Account::_totalNbDeposits << \
				";withdrawals:" << Account::_totalNbWithdrawals \
				<< '\n';
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
				";amount:" << _amount << \
				";deposits:" << _nbDeposits << \
				";withdrawals:" << _nbWithdrawals \
				<< '\n';
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::makeDeposit(int deposit)
{
	int	_p_amount;
	int	nb_deposits;

	_p_amount = _amount;
	_amount = _amount + deposit;
	Account::_totalAmount += deposit;
	nb_deposits = 0;
	if (deposit > 0)
		nb_deposits = 1;
	_nbDeposits += nb_deposits;
	Account::_totalNbDeposits += nb_deposits;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
				";p_amount:" << _p_amount << \
				";deposit:" << deposit << \
				";amount:" << _amount << \
				";nb_deposits:" << _nbDeposits << \
				'\n';
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	_p_amount;
	int	nb_withdrawals;

	_p_amount = _amount;
	if (_p_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << \
					";p_amount:" << _p_amount << \
					";withdrawal:refused" << \
					'\n';
		return (false);
	}
	_amount = _amount - withdrawal;
	Account::_totalAmount -= withdrawal;
	nb_withdrawals = 0;
	if (withdrawal > 0)
		nb_withdrawals = 1;
	_nbWithdrawals += nb_withdrawals;
	Account::_totalNbWithdrawals += nb_withdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
				";p_amount:" << _p_amount << \
				";withdrawal:" << withdrawal << \
				";amount:" << _amount << \
				";nb_withdrawals:" << _nbWithdrawals << \
				'\n';
	return (true);
}
