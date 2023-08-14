/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/14 15:01:25 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Test.hpp"
#include "Color.hpp"

#include <cstdlib>
#include <unistd.h>

typedef enum e_derived {
    AA,
    BB,
    CC
}   e_derived;

/**
 * Randomly instantiate a class. Return a pointer to base.
*/
Base    *generate(void)
{
    int   type = std::rand() % 3;

    switch ((e_derived)type)
    {
    case AA:
        return new A;
    case BB:
        return new B;
    case CC:
        return new C;
    }
    return NULL;
}

/**
 * Identify type of the object using pointer to base.
 * When detecting type using dynamic cast using a pointer, NULL pointer will be returned if it's failed.
 * If success, meaning the "downcasting" is successful.
*/
void    identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Idk." << std::endl;
    return;
}

/**
 * Identify type of object using reference to base.
 * When detecting type using dynamic cast using reference, an exception std::bad_cast will be thrown if it's failed.
 * If successful, meaning the "downcasting" is successful.
*/
void    identify(Base &p)
{
    try {
        Base &base = dynamic_cast<A&>(p);
        (void)base;
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::bad_cast ex)
    {
        // std::cout << ex.what() << std::endl;
    }

    try {
        Base &base = dynamic_cast<B&>(p);
        (void)base;
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::bad_cast ex)
    {
        // std::cout << ex.what() << std::endl;
    }

    try {
        Base &base = dynamic_cast<C&>(p);
        (void)base;
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::bad_cast ex)
    {
        // std::cout << ex.what() << std::endl;
    }
}

Base    **generateN(int N)
{
    Base **arr = new Base*[N];

    for (int i = 0; i < N; i++)
        arr[i] = generate();
    return arr;
}

void    identifyN(Base **arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << BGREEN "Actual type: " RESET;
        arr[i]->say();
        std::cout << BPURPLE "Identify using base to pointer: " RESET;
        identify(arr[i]);
        std::cout << BBLUE "Identify using reference: " RESET;
        identify(*(arr[i]));
        std::cout << std::endl;
    }
}

int main()
{
    // seed the random number generator with a value based on the current time.
    // we generally want to seed the random number generator only once at the beginning of the program,
    // rather than seed once every time you need a random number. Seedin the random number generator with
    // with the same value multiple times during the same program execution could lead to generating the
    // same sequence of random numbers each time, which is undesirable.
    std::srand(std::time(0));
    {
        TEST_TITLE("Identify one derived class through pointer to base & reference");
        Base *base = generate();
        std::cout << BGREEN "Actual type: " RESET;
        base->say();
        std::cout << BPURPLE "Identify using base to pointer:" RESET;
        identify(base);
        std::cout << BBLUE "Identify using reference:" RESET;
        identify(*base);
        delete base;
        TEST_NL();
    }
    {
        TEST_TITLE("Identify N of derived classes through pointer to base & reference");
        const int N = 10;
        Base **arr = generateN(N);
        identifyN(arr, N);
        delete[] arr;
    }
}
