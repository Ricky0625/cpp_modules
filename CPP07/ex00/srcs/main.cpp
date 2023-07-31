/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 19:10:36 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.h"
#include "Color.hpp"
#include "Test.hpp"

int main(void)
{

    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    TEST_NL();

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    TEST_NL();
    
    float e = 1.123f;
    float f = 1.122f;
    float g = 1.122f;
    ::swap<float>(e, f);
    std::cout << "e = " << e << ", f = " << f << ", g = " << g << std::endl;
    std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
    std::cout << "min( g, f ) = " << ::min(g, f) << std::endl;
    std::cout << "max( g, f ) = " << ::max(g, f) << std::endl;
    TEST_NL();

    double h = 12431523423.2453463124124;
    double i = 1412523623142464.23613462241;
    ::swap<double>(h, i);
    std::cout << "h = " << h << ", i = " << i << std::endl;
    std::cout << "min( h, i ) = " << ::min(h, i) << std::endl;
    std::cout << "max( h, i ) = " << ::max(h, i) << std::endl;
    TEST_NL();

    char j = 'J';
    char k = 'K';
    ::swap(j, k);
    std::cout << "j = " << j << ", k = " << k << std::endl;
    std::cout << "min( j, k ) = " << ::min(j, k) << std::endl;
    std::cout << "max( j, k ) = " << ::max(j, k) << std::endl;
    TEST_NL();

    bool l = true;
    bool m = false;
    ::swap(l, m);
    std::cout << "l = " << (l ? "true" : "false") << ", m = " << (m ? "true" : "false") << std::endl;
    std::cout << "min( l, m ) = " << (::min(l, m) ? "true" : "false") << std::endl;
    std::cout << "max( l, m ) = " << (::max(l, m) ? "true" : "false") << std::endl;
    TEST_NL();
}