/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:07:03 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/27 18:40:10 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * Noted that for my copy constructor, I didn't copy an existing object to
 * a new object using the assignment operator. Hence, you will not be able
 * to see the message "Copy assignment operator called" in the output.
 * 
 * Based on what I understand, the copy constructor is used to create a new
 * object from an existing object. The assignment operator is used to
 * assign an existing object to another existing object. Hence, I did not
 * use the overloaded assignment operator in my copy constructor because
 * they are meant for different purposes?
 * 
 * Besides that, if I rely on copy assignment operator in my copy constructor,
 * it seems like code duplication to me. Moreover, if there are any changes or
 * modifications needed in the assignment operator, I will need to make the
 * same changes in the copy constructor as well, which increase the likelihood
 * of making mistakes.
*/
int main()
{
    Fixed   a;
    Fixed   const b( 10 );
    Fixed   const c( 42.42f );
    Fixed   d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
