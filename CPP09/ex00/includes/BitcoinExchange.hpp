/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:19:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/21 17:22:11 by wricky-t         ###   ########.fr       */
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

    private:
        BitcoinExchange( void );
        ~BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange &other );
        BitcoinExchange	&operator=( const BitcoinExchange &other );
};

#endif
