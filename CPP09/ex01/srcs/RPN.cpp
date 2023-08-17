/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:53:45 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/17 18:36:01 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**
 * @brief Check if the current character is one of the operators
 */
static bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}

/**
 * @brief Convert character to int
 */
static int charToInt(char ch)
{
    return (ch - '0');
}

/**
 * Check the syntax of the given string
*/
static void syntaxChecker(const std::string &str, char ch, bool expectingSpace)
{
    // not allow leading/trailing space
    if (str.find_first_of(' ') == 0 || str.find_last_of(' ') == (str.size() - 1))
        throw RPNSyntaxError();
    // if it's neither a digit, a space nor an operator
    if (!(isdigit(ch) || ch == ' ' || isOperator(ch)))
        throw RPNFoundInvalidCharacter();
    // if it's space and not expecting space, throw syntax error
    if (ch == ' ' && !expectingSpace)
        throw RPNSyntaxError();
    // if expecting space and current character is not space
    if ((isdigit(ch) || isOperator(ch)) && expectingSpace)
        throw RPNSyntaxError();
}

/**
 * Get top element and pop the top element off
*/
static long getTopAndPop(std::stack<int> &operands)
{
    long top = operands.top();
    operands.pop();
    return top;
}

/**
 * Solve the equation
*/
static void solveEquation(std::stack<int> &operands, char opr)
{
    if (operands.size() < 2)
        throw RPNNotEnoughtOperands();

    long result;
    long leftOperand;
    long rightOperand;

    switch (opr)
    {
    case '+':
        result = getTopAndPop(operands) + getTopAndPop(operands);
        break;
    case '-':
        rightOperand = getTopAndPop(operands);
        leftOperand = getTopAndPop(operands);
        result = leftOperand - rightOperand;
        break;
    case '/':
        rightOperand = getTopAndPop(operands);
        leftOperand = getTopAndPop(operands);
        if (rightOperand == 0)
            throw RPNUnableToCalculate();
        result = leftOperand / rightOperand; // might need to consider some edge cases here
        break;
    case '*':
        result = getTopAndPop(operands) * getTopAndPop(operands);
        break;
    }
    if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
        throw RPNReachLimit();
    operands.push(result);
}

/**
 * Push element to stack if it's a digit
 * Solve equation if encounter an operator
*/
static void pushAndSolve(std::stack<int> &operands, char ch)
{
    if (isdigit(ch))
        operands.push(charToInt(ch));
    else if (isOperator(ch))
        solveEquation(operands, ch);
}

/**
 * @brief This is where all the magic happens. Parse the given string as RPN
 *        and calculate the output.
 */
int RPN(const std::string &str)
{
    std::stack<int> operands;
    std::string::const_iterator it;
    bool expectingSpace = false;

    for (it = str.begin(); it != str.end(); it++)
    {
        syntaxChecker(str, *it, expectingSpace);
        pushAndSolve(operands, *it);
        expectingSpace = (std::distance(str.begin(), it) % 2 == 0);
    }
    if (operands.size() > 1)
        throw RPNLeftOverOperand();
    return operands.top();
}

// Exception
const char *RPNNotEnoughtOperands::what() const throw()
{
    return NOT_ENOUGH_OPERANDS;
}

const char *RPNSyntaxError::what() const throw()
{
    return SYNTAX_ERROR;
}

const char *RPNFoundInvalidCharacter::what() const throw()
{
    return INVALID_CHARACTER;
}

const char *RPNUnableToCalculate::what() const throw()
{
    return UNABLE_TO_CALCULATE;
}

const char *RPNReachLimit::what() const throw()
{
    return REACH_INT_LIMIT;
}

const char *RPNLeftOverOperand::what() const throw()
{
    return OPERAND_LEFT_OVER;
}
