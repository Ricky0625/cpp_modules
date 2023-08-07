/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:25:36 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/07 18:58:14 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <iomanip>
#include <Color.hpp>

typedef enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} e_type;

typedef enum e_convert_type
{
    E_IMPOSSIBLE,
    E_NANF,
    E_NAN,
    E_PINFF,
    E_PINF,
    E_NINFF,
    E_NINF,
    E_CONVERTABLE
} e_convert_type;

# define FLOAT_MAX_PRECISION 7
# define DOUBLE_MAX_PRECISION 15

// helpers
bool hasOneOccurrence(const std::string &str, char ch);
size_t getPrecision(const std::string &str);

// printers
void printConverted(int *converted, const double value = 0.0, const size_t precision = 0);

// detectors
bool isPseudoLiteral(const std::string &str, int *converted);
bool isConvertable(const std::string &str, double &value, size_t &precision);

#endif