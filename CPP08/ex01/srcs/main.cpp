/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/16 16:16:20 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Test.hpp"
#include "Span.hpp"

int getRandomInt(int min, int max)
{
    int range = max - min + 1;
    int randomValue = min + (std::rand() % range);
    return randomValue;
}

int main()
{
    // seed the random generator
    std::srand(std::time(0));

    const int MAX_CAPACITY = 5;
    std::vector<int> extra_values;
    for (int i = 0; i < MAX_CAPACITY; i++)
        extra_values.push_back(getRandomInt(-100, 100));

    {
        TEST_TITLE("Test 0: Insert using addNumber");
        Span sp = Span(MAX_CAPACITY);

        try {
            int value;
            for (int i = 0; i < MAX_CAPACITY; i++) {
                value = getRandomInt(-100, 100);
                sp.addNumber(value);
            }
            sp.showElements();
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 0A: Insert using addNumber but exceed limit");
        Span sp = Span(MAX_CAPACITY);

        try {
            int value;
            for (int i = 0; i < MAX_CAPACITY + 1; i++) {
                value = getRandomInt(-100, 100);
                sp.addNumber(value);
            }
            sp.showElements();
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 1: Insert using addMultiple");
        Span sp = Span(MAX_CAPACITY);

        try {
            sp.addMultiple(extra_values.begin(), extra_values.end());
            sp.showElements();
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 1: Insert using addMultiple but exceed limit");
        Span sp = Span(MAX_CAPACITY);

        try {
            sp.addMultiple(extra_values.begin(), extra_values.end());
            sp.addMultiple(extra_values.begin(), extra_values.end());
            sp.showElements();
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 2: Insert using addNumber first and use addMultiple to add more");

        Span sp = Span(MAX_CAPACITY);

        try {
            for (int i = 0; i < 3; i++) {
                sp.addNumber(getRandomInt(-100, 100));
            }
            sp.addMultiple(extra_values.begin(), extra_values.end());
            sp.showElements();
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 3: Find the shortest/longest span but has less than 2 elements");
        Span sp = Span(MAX_CAPACITY);

        sp.addNumber(getRandomInt(-100, 100));
        try {
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }

        try {
            std::cout << "Longest span: " << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 4: Find the shortest/longest span");
        Span sp = Span(MAX_CAPACITY);

        try {
            sp.addMultiple(extra_values.begin(), extra_values.end());
            sp.showElements();
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 4A: Find the shortest/longest span with two number");
        Span sp = Span(MAX_CAPACITY);

        try {
            sp.addMultiple(extra_values.begin(), extra_values.begin() + 2);
            sp.showElements();
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 5: Shortest span edge case");
        Span sp = Span(MAX_CAPACITY);

        try {
            sp.addNumber(2147483647);
            sp.addNumber(-2147483648);
            sp.addNumber(0);
            sp.addNumber(100);
            sp.addNumber(1);
            sp.showElements();
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 6: Longest span edge case");
        Span sp = Span(MAX_CAPACITY);

        try {
            sp.addNumber(2147483647);
            sp.addNumber(-2147483648);
            sp.addNumber(0);
            sp.addNumber(100);
            sp.addNumber(1);
            sp.showElements();
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("Test 7: Insert 20000 numbers");
        Span sp = Span(20000);

        try {
            for (int i = 0; i < 20000; i++) {
                sp.addNumber(getRandomInt(-20000, 20000));
            }
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        TEST_HR();
    }
}
