#include <iostream>
#include <sstream>
#include <iomanip>
#include "Account.class.hpp"

std::string	my_itoa(int number){
	std::stringstream ss;
	ss << number;
	return (ss.str());
}

Account::Account(int initial_deposit){
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_totalAmount += _amount;
	Account::_nbAccounts++;
	_accountIndex = Account::_nbAccounts;

	_displayTimestamp();
	std::cout << "index:" + my_itoa(_accountIndex) + ";";
	std::cout << "amount:" + my_itoa(_amount) + ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" + my_itoa(_accountIndex) + ";";
	std::cout << "amount:" + my_itoa(_amount) + ";";
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "index:" + my_itoa(_accountIndex) + ";";
	std::cout << "p_amount:" + my_itoa(_amount) + ";";
	std::cout << "deposit:" + my_itoa(deposit) + ";";
	_amount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << "amount:" + my_itoa(_amount) + ";";
	std::cout << "nb_deposits:" + my_itoa(_nbDeposits);
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" + my_itoa(_accountIndex) + ";";
	std::cout << "p_amount:" + my_itoa(_amount) + ";";
	if (_amount - withdrawal >= 0){
		std::cout << "withdrawal:" + my_itoa(withdrawal) + ";";
		_amount -= withdrawal;
		_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << "amount:" + my_itoa(_amount) + ";";
		std::cout << "nb_withdrawals:" + my_itoa(_nbWithdrawals);
		std::cout << std::endl;
		return (true);
	} else {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

int Account::checkAmount(void) const {
	return (_amount);
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" + my_itoa(_accountIndex) + ";";
	std::cout << "amount:" + my_itoa(_amount) + ";";
	std::cout << "deposits:" + my_itoa(_nbDeposits) + ";";
	std::cout << "withdrawals:" + my_itoa(_nbWithdrawals);
	std::cout << std::endl;
}

int Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);
};

int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
};

int	Account::getNbWithdrawals(void){
	return (Account::_totalNbWithdrawals);
};

void Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:" + my_itoa(Account::_nbAccounts + 1) + ";";
	std::cout << "total:" + my_itoa(Account::_totalAmount) + ";";
	std::cout << "deposits:" + my_itoa(Account::_totalNbDeposits) + ";";
	std::cout << "withdrawals:" + my_itoa(Account::_totalNbWithdrawals);
	std::cout << std::endl;
}

void Account::_displayTimestamp(void){
	time_t	now = time(0);
	tm		*ltm = localtime(&now);


	std::cout << "[" << 1900 + ltm->tm_year;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << 1 + ltm->tm_mon;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_mday;
	std::cout << std::resetiosflags(std::ios::showbase);
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_min;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_sec;
	std::cout << std::resetiosflags(std::ios::showbase);
	std::cout << "]";
}

int	Account::_nbAccounts = -1;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
