/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:21:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/17 18:05:49 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

# define RULES "RULES:\n<str> should fulfill the following format:\n- numbers that ranges from 0-9\n- acceptable operators are: + - / *\n- between number and operator, they should be seperated by only one space\n- should not have any leading/trailing spaces"
# define INVALID_USAGE "[ERROR]: Invalid usage! ./RPN <str>"
# define EMPTY_STRING "[ERROR]: Empty string!"
# define NOT_ENOUGH_OPERANDS "[ERROR]: Not enough operands to compute"
# define SYNTAX_ERROR "[ERROR]: Syntax error! Please refer to the rules again!"
# define INVALID_CHARACTER "[ERROR]: Invalid character found!"
# define UNABLE_TO_CALCULATE "[ERROR]: Unable to calculate!"
# define REACH_INT_LIMIT "[ERROR]: Reach integer limit!"
# define OPERAND_LEFT_OVER "[ERROR]: Found leftover operands!"

// Function prototype
int RPN(const std::string &str);

// Exception
class RPNNotEnoughtOperands : public std::exception {
    public:
        const char *what() const throw();
};
class RPNSyntaxError : public std::exception {
    public:
        const char *what() const throw();
};
class RPNFoundInvalidCharacter : public std::exception {
    public:
        const char *what() const throw();
};
class RPNUnableToCalculate : public std::exception {
    public:
        const char *what() const throw();
};
class RPNReachLimit : public std::exception {
    public:
        const char *what() const throw();
};
class RPNLeftOverOperand : public std::exception {
    public:
        const char *what() const throw();
};

#endif
