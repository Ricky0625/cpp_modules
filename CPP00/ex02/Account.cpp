/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:59:57 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/22 17:36:44 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::string;

enum    e_obj_state {
    INSTANTIATE,
    DESTRUCT
};

// Initialize static data members.
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Log account state to stdout based on the given state.
static void _logAccountState(int index, int amount, e_obj_state state) {

    const char *state_str;    
    
    if (state != INSTANTIATE && state != DESTRUCT)
        return ;
    state_str = (state == INSTANTIATE ? "created" : "closed");
    std::cout << "index:" << index << ";amount:" << amount << ";" << state_str << "\n";
}

// Default constructor. Note that this function does not declared in the header file.
Account::Account() {}

// Overloaded constructor.
// Note that initialization lists were not used here because intialization lists
// can only initialize non-static data members.
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    _logAccountState(_accountIndex, _amount, INSTANTIATE);
}

// Destructor.
Account::~Account() {
    _displayTimestamp();
    _logAccountState(_accountIndex, _amount, DESTRUCT);
}

// A static member getter function.
// when define a static member function, the static keyword is not required
int     Account::getNbAccounts() {
    return _nbAccounts;
}

// A static member getter function.
int     Account::getTotalAmount() {
    return _totalAmount;
}

// A static member getter function.
int     Account::getNbDeposits() {
    return _totalNbDeposits;
}

// A static member getter function.
int     Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

// A static member function. Show the current state of the account.
void    Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}

// A member function. Make a deposit.
void    Account::makeDeposit(int deposit) {
    _totalAmount += deposit;
    ++_totalNbDeposits;
    ++_nbDeposits;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << "\n";
}

// A member function. Make a withdrawal.
bool    Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:";
    if (checkAmount() < withdrawal || withdrawal < 0)
    {
        std::cout << "refused\n";
        return false;
    }
    std::cout << withdrawal << ";";
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    ++_totalNbWithdrawals;
    ++_nbWithdrawals;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
    return true;
}

// Getter. Return the current amount of the account.
int     Account::checkAmount(void) const {
    return (_amount);
}

// A member function. Show the current state of the account.
void    Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

/**
 * @brief Display current timestamp in the following format: [YYYYMMDD_HHMMSS]
 * 
 * @details
 * 1. Get current time in seconds since epoch.
 * 2. Convert current time to local time.
 * 3. Format local time to string.
 * 4. Print formatted time to stdout.
*/
void    Account::_displayTimestamp() {
    char        timestamp[16];
    std::time_t current_time = std::time(NULL);

    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&current_time));
    std::cout << "[" << timestamp << "] ";
}
