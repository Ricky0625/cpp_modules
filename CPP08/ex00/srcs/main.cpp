/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/15 15:47:23 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Test.hpp"
#include "easyfind.h"

// all the sequence containers for testing
#include <vector>
#include <deque>
#include <list>

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
    {
        TEST_TITLE("VECTOR TEST");
        TEST_DESC("Vector is a dynamic array-like container in STL.");
        std::vector<int> myvector;
        int size = getRandomInt(2, 10);
        std::cout << "Initializing a vector with the size of " << size << "." << std::endl;

        // add elements into vector, use push_back to insert
        for (int i = 0; i < size; i++)
            myvector.push_back(getRandomInt(-100, 100));

        // print the elements out
        std::cout << "ELEMENTS: ";
        showElements<std::vector<int> >(myvector);

        // find value
        int findValue;
        std::cout << "Find this (value besides int will crash): ";
        std::cin >> findValue;
        std::cout << std::endl;
        try
        {
            size_t index = easyfind<std::vector<int> >(myvector, findValue);
            std::cout << "Element found at index " << index << ".\n";
        }
        catch (const std::exception& ex)
        {
            std::cout << BRED << ex.what() << RESET << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("DEQUE TEST");
        TEST_DESC("Deque is short for 'double-ended queue', which is a sequence container that allows efficient insertion and deletion at both its beginning and its end.");
        std::deque<int> mydeque;
        int size = getRandomInt(2, 10);
        std::cout << "Initializing a deque with the size of " << size << "." << std::endl;

        // add elements into deque, can use push_front or push_back
        for (int i = 0; i < size; i++)
        {
            int value = getRandomInt(-100, 100);
            if (value % 2 == 0)
                mydeque.push_back(value);
            else
                mydeque.push_front(value);
        }

        // print the elements out
        std::cout << "ELEMENTS: ";
        showElements<std::deque<int> >(mydeque);

        // find value
        int findValue;
        std::cout << "Find this (value besides int will crash): ";
        std::cin >> findValue;
        std::cout << std::endl;
        try
        {
            size_t index = easyfind<std::deque<int> >(mydeque, findValue);
            std::cout << "Element found at index " << index << ".\n";
        }
        catch (const std::exception& ex)
        {
            std::cout << BRED << ex.what() << RESET << std::endl;
        }
        TEST_HR();
    }
    {
        TEST_TITLE("LIST TEST");
        TEST_DESC("List is a doubly-linked list container in C++.");
        std::list<int> mylist;
        int size = getRandomInt(2, 10);
        std::cout << "Initializing a list with the size of " << size << "." << std::endl;

        // add elements into list, can use push_front or push_back as well
        for (int i = 0; i < size; i++)
        {
            int value = getRandomInt(-100, 100);
            if (i > 4)
                mylist.push_front(value);
            else
                mylist.push_back(value);
        }

        // print the elements out
        std::cout << "ELEMENTS: ";
        showElements<std::list<int> >(mylist);

        // find element
        int findValue;
        std::cout << "Find this (value besides int will crash): ";
        std::cin >> findValue;
        std::cout << std::endl;
        try
        {
            size_t index = easyfind<std::list<int> >(mylist, findValue);
            std::cout << "Element found at index " << index << ".\n";
        }
        catch (const std::exception& ex)
        {
            std::cout << BRED << ex.what() << RESET << std::endl;
        }
        TEST_HR();
    }
}
