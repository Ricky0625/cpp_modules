/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:44 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/23 16:52:15 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define INVALID_USAGE "[ERROR]: Invalid usage!\n./PmergeMe <elements>\nNOTE: All elements should be positive integers!"

# include <iostream>
# include <vector>
# include <string>
# include <iterator>

# include "Color.hpp"

typedef std::vector<std::string> StrVector;
typedef std::vector<int> IntVector;

class PmergeMe {
    public:
        static void mergeMe(StrVector &elements);
        
        // exceptions
        class PmergeMeInvalidArgument : public std::exception {
            public:
                PmergeMeInvalidArgument(const std::string &arg): _args(arg) {};
                ~PmergeMeInvalidArgument() throw() {};
                const char *what() const throw();
            private:
                std::string _args;
        };
        class PmergeMeValueExceedRange : public std::exception {
            public:
                PmergeMeValueExceedRange(const std::string &arg): _args(arg) {};
                ~PmergeMeValueExceedRange() throw() {};
                const char *what() const throw();
            private:
                std::string _args;
        };
    private:
        PmergeMe( void );
        ~PmergeMe( void );
        PmergeMe( const PmergeMe &other );
        PmergeMe	&operator=( const PmergeMe &other );
};

#endif
