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
        int     get_index(void);
        int     get_total(void);
        void    show_cmds(void);
        void    add_contact(void);
        void    search_contact(void);
        void    exit_phonebook(void);
        void    list_contacts(void);
    private:
        int     index;
        int     total;
        Contact contacts[MAX_CONTACTS];
};

#endif
