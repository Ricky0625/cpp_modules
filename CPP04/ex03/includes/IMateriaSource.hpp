/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:41:17 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 17:41:55 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include <iostream>
# include "AMateria.hpp"

// Interface for materia source
class IMateriaSource {
    public:
        virtual ~IMateriaSource( void ) {};
        virtual void learnMateria( AMateria* ) = 0;
        virtual AMateria* createMateria( std::string const & type ) = 0;
};

#endif
