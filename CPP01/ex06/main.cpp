/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:08:04 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/25 15:24:48 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    log_err_msg(void)
{
    std::cout << "./harp2.0 <level code>" << std::endl;
    std::cout << "\nLevel codes: DEBUG, INFO, WARNING, ERROR" << std::endl;
}

int main(int ac, char **av) {
    
    if (ac != 2)
    {
        log_err_msg();
        exit(EXIT_FAILURE);   
    }

    Harl    harl;

    harl.complain(std::string(av[1]));
}
