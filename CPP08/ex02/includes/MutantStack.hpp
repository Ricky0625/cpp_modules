/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:47:54 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/16 18:00:33 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T >
class MutantStack : public std::stack<T> {

    public:
        typedef typename std::stack<T>::value_type value_type;
        typedef typename std::stack<T>::container_type container_type;
        typedef typename std::stack<T>::size_type size_type;
        typedef typename container_type::iterator iterator;
        typedef typename container_type::const_iterator const_iterator;
        typedef typename container_type::reverse_iterator reverse_iterator;
        typedef typename container_type::const_reverse_iterator const_reverse_iterator; 

        MutantStack( void ) {};
        ~MutantStack( void ) {};
        MutantStack( const MutantStack &other ) { _stack = other._stack; };
        MutantStack	&operator=( const MutantStack &other ) { _stack = other.stack; };

        iterator begin() { return this->c.begin(); };
        const_iterator begin() const { return this->c.begin(); };
        iterator end() { return this->c.end(); };
        const_iterator end() const { return this->c.end(); };
        reverse_iterator rbegin() { return this->c.rbegin(); };
        const_reverse_iterator rbegin() const { return this->c.rbegin(); };
        reverse_iterator rend() { return this->c.rend(); };
        const_reverse_iterator rend() const { return this->c.rend(); };

    private:
        std::stack<T> _stack;
};

#endif
