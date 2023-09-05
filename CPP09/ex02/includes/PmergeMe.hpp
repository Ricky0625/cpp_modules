/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:44 by wricky-t          #+#    #+#             */
/*   Updated: 2023/09/05 16:07:22 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define INVALID_USAGE "[ERROR]: Invalid usage!\n./PmergeMe <elements>\nNOTE: All elements should be positive integers!"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <iterator>
#include <iomanip>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>

#include "GroupIterator.hpp"
#include "Color.hpp"

typedef std::vector<std::string> StrVect;
typedef std::vector<int> IntVect;
typedef std::deque<int> IntDeq;
typedef IntVect::iterator IntVectIte;
typedef IntDeq::iterator IntDeqIte;
typedef std::list<GroupIterator<IntVectIte> > MainChain;
typedef MainChain::iterator MainChainIte;
typedef std::vector<MainChainIte> Pend;

class PmergeMe
{
public:
    static void mergeMe(StrVect &elements);

    // exceptions
    class PmergeMeInvalidArgument : public std::exception
    {
    public:
        PmergeMeInvalidArgument(const std::string &arg) : _args(arg){};
        ~PmergeMeInvalidArgument() throw(){};
        const char *what() const throw();

    private:
        std::string _args;
    };
    class PmergeMeValueExceedRange : public std::exception
    {
    public:
        PmergeMeValueExceedRange(const std::string &arg) : _args(arg){};
        ~PmergeMeValueExceedRange() throw(){};
        const char *what() const throw();

    private:
        std::string _args;
    };
    class PmergeMeNotEnoughElements : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class PmergeMeDuplicateElement : public std::exception
    {
    public:
        PmergeMeDuplicateElement(const std::string &arg) : _args(arg){};
        ~PmergeMeDuplicateElement() throw(){};
        const char *what() const throw();

    private:
        std::string _args;
    };

private:
    PmergeMe(void);
    ~PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
};

#endif
