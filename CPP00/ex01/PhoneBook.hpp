/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:42 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/21 18:12:21 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8
# define BCYAN "\033[1;34m"
# define DEF "\033[0m"

class PhoneBook {

    public:
        PhoneBook();
        ~PhoneBook();
        /**
         * @brief Getters
         * @attention
         * The const keyword after the function declaration means that the function
         * is not allowed to modify the object for which it is called.
        */
        int     getIndex() const;
        int     getTotal() const;
        // helpers
        void    showCmds();
        void    addContact();
        void    searchContact();
        void    exitPhonebook();
        void    listContacts();
    private:
        int     _index;
        int     _total;
        Contact contacts[MAX_CONTACTS];
};

#endif
