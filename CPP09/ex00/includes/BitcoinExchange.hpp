/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:19:32 by wricky-t          #+#    #+#             */
/*   Updated: 2024/01/05 16:07:50 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <exception>
# include <fstream>
# include <sstream>
# include <map>
# include <ctime>
# include <utility>
# include <cstdlib>

# include "Color.hpp"

# define BTC_DATABASE "data.csv"

# define INVALID_USAGE "Invalid usage!\n./btc <file>"

typedef enum e_type {
    DATABASE,
    READFILE
}   e_type;

typedef std::map<time_t, float> MapType;
typedef const std::map<time_t, float> CMapType;

class BitcoinExchange {
    public:
        static void    bitcoinExchange(const std::string &file);
        
        // exception
        class BTCDatabaseDoesNotExist : public std::exception {
            public:
                const char *what() const throw();
        };
        class BTCErrorWhenOpenFile : public std::exception {
            public:
                const char *what() const throw();
        };
        class BTCErrorWhileParsingDatabaseFile : public std::exception {
            public:
                const char *what() const throw();
        };
        class BTCInvalidDateFormat : public std::exception {
            public:
                const char *what() const throw();
        };
        class BTCInvalidValueFormat : public std::exception {
            public:
                const char *what() const throw();
        };
        class BTCNoDateGiven : public std::exception {
            public:
                const char *what() const throw(); 
        };
        class BTCNoValueGiven : public std::exception {
            public:
                const char *what() const throw();  
        };
        class BTCValueTooSmall : public std::exception {
            public:
                const char *what() const throw();
        };
        class BTCValueTooBig : public std::exception {
            public:
                const char *what() const throw();
        };
        class BTCEmptyLine : public std::exception {
            public:
                const char *what() const throw();
        };
        class BTCFailedToParseLine : public std::exception {
            public:
                const char *what() const throw();
        };

    private:
        BitcoinExchange( void );
        ~BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange &other );
        BitcoinExchange	&operator=( const BitcoinExchange &other );
};

bool isLeapYear(int year);
bool isValidDate(int year, int month, int day);
time_t strToEpochTime(const std::string &dateStr);
std::string epochTimeToStr(time_t epochTime);
bool isValidDateFormat(const std::string &date);
bool isIntFormat(const std::string &value);
bool isFloatFormat(const std::string &value);
bool isValidValueFormat(const std::string &value);
bool onlyHasOneOccurrence(const std::string &str, char target);

#endif
