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

using std::string;

enum    e_obj_state {
    INSTANTIATE,
    DESTRUCT
};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void log_obj_state(int index, int amount, e_obj_state state) {

    const char *state_str;    
    
    if (state != INSTANTIATE && state != DESTRUCT)
        return ;
    state_str = (state == INSTANTIATE ? "created" : "closed");
    std::cout << "index:" << index << ";amount:" << amount << ";" << state_str << "\n";
}

Account::Account(void) {}

Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    log_obj_state(this->_accountIndex, this->_amount, INSTANTIATE);
}

Account::~Account(void) {
    _displayTimestamp();
    log_obj_state(this->_accountIndex, this->_amount, DESTRUCT);
}

int     Account::getNbAccounts(void) {
    return _nbAccounts;
}

int     Account::getTotalAmount(void) {
    return _totalAmount;
}

int     Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int     Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}

void    Account::makeDeposit(int deposit) {
    _totalAmount += deposit;
    ++_totalNbDeposits;
    ++this->_nbDeposits;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

bool    Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:";
    if (checkAmount() < withdrawal || withdrawal < 0)
    {
        std::cout << "refused\n";
        return false;
    }
    std::cout << withdrawal << ";";
    _totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    ++_totalNbWithdrawals;
    ++this->_nbWithdrawals;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
    return true;
}

int     Account::checkAmount(void) const {
    return (this->_amount);
}

void    Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}

void    Account::_displayTimestamp(void) {
    char        timestamp[16];
    std::time_t current_time = std::time(NULL);

    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&current_time));
    std::cout << "[" << timestamp << "] ";
}
