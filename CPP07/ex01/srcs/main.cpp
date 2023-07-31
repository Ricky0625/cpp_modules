/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 21:27:10 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"
#include "Color.hpp"
#include "Test.hpp"

int main(void)
{
    std::size_t ARRSIZE = 5;
    int intArr[5] = { 1, 2, 3, 4, 5 };
    std::string strArr[5] = { "Mochi", "Karipap", "Cheese", "Soda", "Potato" };
    double douArr[5] = {1244135.345, 0.123, 12341.2, 452.3, 1414251.9 };
    float floArr[5] = { 0.9f, 0.872f, 125.67f, 1356.8f, 987.4f };
    bool boolArr[5] = { false, false, true, true, false };

    {
        iter(intArr,ARRSIZE, &squareElement);
        iter(intArr,ARRSIZE, &print<int>);
        TEST_NL();
        iter(intArr,ARRSIZE, &tripleElement);
        iter(intArr,ARRSIZE, &print<int>);
        TEST_NL();
        iter(intArr, ARRSIZE, &oddOrEven);
        TEST_NL();
    }
    {
        iter(strArr, ARRSIZE, &meowSay);
        for (std::size_t i = 0; i < ARRSIZE; i++)
            std::cout << strArr[i] << std::endl;
        TEST_NL();   
    }
    {
        iter(douArr, ARRSIZE, &colorize<double>);
        TEST_NL();
        iter(intArr, ARRSIZE, &colorize<int>);
        TEST_NL();
        iter(strArr, ARRSIZE, &colorize<std::string>);
        TEST_NL();
        iter(floArr, ARRSIZE, &colorize<float>);
        TEST_NL();
        iter(boolArr, ARRSIZE, &colorize<bool>);
        TEST_NL();
    }
}