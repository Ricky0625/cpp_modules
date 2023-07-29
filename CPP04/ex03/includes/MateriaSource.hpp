/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:42:45 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 17:51:17 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include "AMateria.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource( void );
        ~MateriaSource( void );
        MateriaSource( const MateriaSource &other );
        MateriaSource	&operator=( const MateriaSource &other );

        // override
        void learnMateria( AMateria* );
        AMateria* createMateria( std::string const & type );

    private:
        static const int MAX_SLOTS = 4;
        int         _slots;
        AMateria    *_shelf[MAX_SLOTS];
};

#endif
