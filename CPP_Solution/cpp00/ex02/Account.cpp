/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:51:26 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/20 13:40:17 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):_accountIndex(_nbAccounts), 
                _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";amount:" << checkAmount()
                << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
	std::cout << " index:" << _accountIndex 
                << ";amount:" << checkAmount()
                << ";closed" << std::endl;
} 

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";amount:" << checkAmount()
                << ";deposits:" << _nbDeposits 
                << ";withdrawals:" << _nbWithdrawals
		        << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    int	previous_amount = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";p_amount:" << previous_amount
				<< ";deposit:" << deposit 
                << ";amount:" << checkAmount()
				<< ";nb_deposits:" << _nbDeposits 
                << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex 
                    << ";p_amount:" << checkAmount()
				    << ";withdrawals:refused" << std::endl;
        return false;
    }
    int	previous_amount = _amount;
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";p_amount:" << previous_amount
				<< ";withdrawal:" << withdrawal 
                << ";amount:" << checkAmount()
				<< ";nb_withdrawals:" 
                << _nbWithdrawals << std::endl;
	return true;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
            << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals()
		    << std::endl;
}

void	Account::_displayTimestamp(void)
{
    std::time_t currentTime = std::time(NULL);
    std::tm *datetime = std::localtime(&currentTime);
    
    char temp[50];
    std::strftime(temp, sizeof(temp), "[%Y%m%d_%H%M%S]", datetime);
    std::cout << temp;
}

int	Account::getTotalAmount(void)
{
    return _totalAmount;
}

int	Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

int	Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int	Account::getNbAccounts()
{
    return _nbAccounts;
}

int	Account::checkAmount() const
{
	return (_amount);
}
