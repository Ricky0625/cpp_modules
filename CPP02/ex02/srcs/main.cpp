/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:07:03 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/29 14:47:32 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;
using std::endl;
using std::string;

string  evaluate(int res) {
    if (res == true)
        return "TRUE";
    return "FALSE";
}

void    detailed_tests(void) {
    Fixed a;
    Fixed b( 625 );
    Fixed c( 625.25f );
    Fixed d( b );
    Fixed e;
    Fixed f( 526.2525f );
    Fixed g( 526 );

    e = c;
    cout << "================= VARS =================" << endl
         << "a: " << a << endl
         << "b: " << b << endl
         << "c: " << c << endl
         << "d: " << d << endl
         << "e: " << e << endl
         << "f: " << f << " (Lost accuracy)" << endl
         << "g: " << g << endl
         << endl << endl;
    
    cout << "========== COMPARISON OPERATORS =========" << endl
         << "GREATER THAN (>)" << endl
         << "b > g: " << evaluate(b > g) << endl
         << "g > b: " << evaluate(g > b) << endl
         << "b > d: " << evaluate(b > d) << endl
         << "c > b: " << evaluate(c > b) << endl
         << "b > c: " << evaluate(b > c) << endl
         << "c > f: " << evaluate(c > f) << endl
         << "f > c: " << evaluate(f > c) << endl
         << endl
         << "LESS THAN (<)" << endl
         << "b < g: " << evaluate(b < g) << endl
         << "g < b: " << evaluate(g < b) << endl
         << "b < d: " << evaluate(b < d) << endl
         << "c < b: " << evaluate(c < b) << endl
         << "b < c: " << evaluate(b < c) << endl
         << "c < f: " << evaluate(c < f) << endl
         << "f < c: " << evaluate(f < c) << endl
         << endl
         << "GREATER AND EQUAL (>=)" << endl
         << "b >= g: " << evaluate(b >= g) << endl
         << "g >= b: " << evaluate(g >= b) << endl
         << "b >= d: " << evaluate(b >= d) << endl
         << "c >= b: " << evaluate(c >= b) << endl
         << "b >= c: " << evaluate(b >= c) << endl
         << "c >= f: " << evaluate(c >= f) << endl
         << "f >= c: " << evaluate(f >= c) << endl
         << endl
         << "LESS AND EQUAL (<=)" << endl
         << "b <= g: " << evaluate(b <= g) << endl
         << "g <= b: " << evaluate(g <= b) << endl
         << "b <= d: " << evaluate(b <= d) << endl
         << "c <= b: " << evaluate(c <= b) << endl
         << "b <= c: " << evaluate(b <= c) << endl
         << "c <= f: " << evaluate(c <= f) << endl
         << "f <= c: " << evaluate(f <= c) << endl
         << endl
         << "EQUAL (==)" << endl
         << "b == d: " << evaluate(b == d) << endl
         << "b == c: " << evaluate(b == c) << endl
         << "c == e: " << evaluate(c == e) << endl
         << "e == f: " << evaluate(e == f) << endl
         << "b == g: " << evaluate(b == g) << endl
         << endl
         << "NOT EQUAL (!=)" << endl
         << "b != d: " << evaluate(b != d) << endl
         << "b != c: " << evaluate(b != c) << endl
         << "c != e: " << evaluate(c != e) << endl
         << "e != f: " << evaluate(e != f) << endl
         << "b != g: " << evaluate(b != g) << endl
         << endl << endl;
        
    cout << "========== ARITHMETIC OPERATORS =========" << endl
         << "ADDITION (+)" << endl
         << "b + d: " << b + d << endl
         << "b + c: " << b + c << endl
         << "e + f: " << e + f << endl
         << "b + c + d + e + f: " << b + c + d + e + f << endl
         << endl
         << "SUBSTRACTION (-)" << endl
         << "b - d: " << b - d << endl
         << "b - c: " << b - c << endl
         << "e - f: " << e - f << endl
         << "f - e: " << f - e << endl
         << "b - c - d - e - f: " << b - c - d - e - f << endl
         << endl
         << "MULTIPLICATION (*)" << endl
         << "b * 2: " << b * Fixed(2) << endl
         << "b * -2: " << b * Fixed(-2) << endl
         << "e * 0.25: " << e * Fixed(0.25f) << endl
         << "e * 0.254: " << e * Fixed(0.254f) << " (lost accuracy)" << endl
         << "f * 200: " << f * Fixed(200) << endl
         << "g * 0: " << g * Fixed(0) << endl
         << endl
         << "DIVISION (/)" << endl
         << "b / 0: " << b / Fixed(0) << endl
         << "0 / 1: " << a / Fixed(1) << endl
         << "b / 5: " << b / Fixed(5) << endl
         << "b / -5: " << b / Fixed(-5) << endl
         << "b / 5.5: " << b / Fixed(5.5f) << endl
         << endl << endl;
    
    /**
     * In a fixed point number representation, the increment/decrement operator does not
     * necessarily increment the value by 1. The incre/decre operator typically adds the
     * smallest representable increment to the fixed point number. This smallest unit
     * in determined by the number of bits used to represent the fractional part of the
     * number. For example, if 8 bits are used to represent the fractional part, the
     * smallest increment would be `1/256` or approximately `0.00390625`.
     * So for `int`, since there's no fractional part, the smallest unit is 1. Hence when
     * we increment an `int`, it increments by `1`.
    */
    cout << "========== INCRE/DECRE OPERATORS =========" << endl
         << "PRE-INCREMENT (++x)" << endl
         << "++b: " << ++b << endl
         << "++c: " << ++c << endl
         << endl
         << "PRE-DECREMENT (--x)" << endl
         << "--b: " << --b << endl
         << "--c: " << --c << endl
         << endl
         << "POST-INCREMENT (x++)" << endl
         << "b++: " << b++ << endl
         << "b: " << b << endl
         << "c++: " << c++ << endl
         << "c: " << c << endl
         << endl
         << "POST-DECREMENT (x--)" << endl
         << "b--: " << b-- << endl
         << "b: " << b << endl
         << "c--: " << c-- << endl
         << "c: " << c << endl
         << endl << endl;

    const Fixed h( 1234 );
    const Fixed i( 1234.69f );
    const Fixed j( 4321 );
    const Fixed k( 4321.96f );

    cout << "============ MIN/MAX FUNCTIONS ===========" << endl
         << "MIN(x, y)" << endl
         << "min(a, b): " << Fixed::min( a, b ) << endl
         << "min(b, c): " << Fixed::min( b, c ) << endl
         << "min(c, b): " << Fixed::min( c, b ) << endl
         << "min(b, b): " << Fixed::min( b, b ) << endl
         << "min(c, c): " << Fixed::min( c, c ) << endl
         << "min(b, -625): " << Fixed::min( b, Fixed(-625) ) << endl
         << endl
         << "MAX(x, y)" << endl
         << "max(a, b): " << Fixed::max( a, b ) << endl
         << "max(b, c): " << Fixed::max( b, c ) << endl
         << "max(c, b): " << Fixed::max( c, b ) << endl
         << "max(b, b): " << Fixed::max( b, b ) << endl
         << "max(c, c): " << Fixed::max( c, c ) << endl
         << "max(b, -625): " << Fixed::max( b, Fixed(-625) ) << endl
         << endl
         << "MIN(const x, const y)" << endl
         << "min(h, j): " << Fixed::min( h, j ) << endl
         << "min(h, i): " << Fixed::min( h, i ) << endl
         << "min(j, j): " << Fixed::min( j, j ) << endl
         << "min(j, k): " << Fixed::min( j, k ) << endl
         << "min(i, k): " << Fixed::min( i, k ) << endl
         << endl
         << "MAX(const x, const y)" << endl
         << "max(h, j): " << Fixed::max( h, j ) << endl
         << "max(h, i): " << Fixed::max( h, i ) << endl
         << "max(j, j): " << Fixed::max( j, j ) << endl
         << "max(j, k): " << Fixed::max( j, k ) << endl
         << "max(i, k): " << Fixed::max( i, k ) << endl
         << endl << endl;
}

void    subject_tests(void) {
    Fixed   a;
    Fixed   const b( Fixed( 5.05f ) * Fixed( 2 ) );

    cout << a << endl;
    cout << ++a << endl;
    cout << a << endl;
    cout << a++ << endl;
    cout << a << endl;
    cout << b << endl;
    cout << Fixed::max( a, b ) << endl;   
}

void    show_error(void) {
    cout << "./fixed <TEST_TYPE>" << endl
         << "TEST_TYPE:" << endl
         << "D = Detailed test cases" << endl
         << "S = Test cases given by the subject" << endl;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1] == string("D"))
            detailed_tests();
        else if (av[1] == string("S"))
            subject_tests();
        else {
            show_error();
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
    show_error();
    return EXIT_FAILURE;
}
