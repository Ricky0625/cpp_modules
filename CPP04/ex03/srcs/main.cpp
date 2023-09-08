/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:48 by wricky-t          #+#    #+#             */
/*   Updated: 2023/09/08 15:30:41 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void    preliminary_tests()
{
    {
        // TEST_TITLE("Test 0: Should not be able to instantiate an AMateria, which is an abstract class");
        // TEST_NL();
        // AMateria a("test");
        // AMateria *b = new AMateria("test");
    }
    {
        TEST_TITLE("Test 1: Instantiate an Ice and Cure using its type");
        TEST_DESC("To test whether the objects are created correctly");
        TEST_NL();
        
        TEST_TITLE_S("Instantiate Ice (concrete type)");
        Ice ice;
        std::cout << GREEN << "Am I an ice? " << ice.getType() << RESET << std::endl;
        TEST_TITLE_S("Instantiate Cure (concrete type)");
        Cure cure;
        std::cout << GREEN << "Am I a cure? " << cure.getType() << RESET << std::endl;
        
        TEST_NL();

        TEST_TITLE_S("Instantiate Ice (pointer to concrete type)");
        Ice *ice2 = new Ice();
        std::cout << GREEN << "Am I an ice? " << ice2->getType() << RESET << std::endl;
        TEST_TITLE_S("Instantiate Cure (pointer to concrete type)");
        Cure *cure2 = new Cure();
        std::cout << GREEN << "Am I a cure? " << cure2->getType() << RESET << std::endl;

        TEST_NL();
        std::cout << BWHITE << "Destruct Pointers to concrete types" << RESET << std::endl;
        delete ice2;
        delete cure2;

        TEST_NL();
        TEST_LEAKS(1);   
        std::cout << BWHITE << "Destruct concrete types" << RESET << std::endl;
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 2: Clone Ice and Cure");
        TEST_DESC("To test whether the objects are cloned correctly");
        TEST_DESC_CONT("The cloned objects should have the same type as the original ones and at the same time, they should have different addresses");
        TEST_NL();

        TEST_TITLE_S("Instantiate Ice (concrete type)");
        Ice ice;
        AMateria *ice2 = ice.clone();
        std::cout << GREEN << "Address of ice: " << &ice << RESET << std::endl;
        std::cout << GREEN << "Address of ice2: " << ice2 << RESET << std::endl; 

        TEST_TITLE_S("Instantiate Cure (concrete type)");
        Cure cure;
        AMateria *cure2 = cure.clone();
        std::cout << GREEN << "Address of cure: " << &cure << RESET << std::endl;
        std::cout << GREEN << "Address of cure2: " << cure2 << RESET << std::endl;

        TEST_NL();

        TEST_TITLE_S("Instantiate Ice (pointer to concrete type)");
        Ice *ice3 = new Ice();
        AMateria *ice4 = ice3->clone();
        std::cout << GREEN << "Address of ice3: " << ice3 << RESET << std::endl;
        std::cout << GREEN << "Address of ice4: " << ice4 << RESET << std::endl;

        TEST_TITLE_S("Instantiate Cure (pointer to concrete type)");
        Cure *cure3 = new Cure();
        AMateria *cure4 = cure3->clone();
        std::cout << GREEN << "Address of cure3: " << cure3 << RESET << std::endl;
        std::cout << GREEN << "Address of cure4: " << cure4 << RESET << std::endl;
        
        TEST_NL();
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 3: Basic functionality of Character");
        TEST_NL();

        TEST_TITLE_S("Spawn a character and gets his/her name");
        Character a("Max");
        std::cout << "Name: " << a.getName() << std::endl;
        TEST_NL();

        TEST_TITLE_S("Equip the character with Ice and Cure");
        AMateria *ice = new Ice();
        AMateria *ice2 = new Ice();
        AMateria *cure = new Cure();
        AMateria *cure2 = new Cure();
        AMateria *cure3 = new Cure();
        a.equip(ice);
        a.equip(ice2);
        a.equip(cure);
        a.equip(cure2);
        a.equip(cure3);
        a.unequip(0);
        a.unequip(1);
        a.unequip(2);
        a.showSlots(INVENTORY);
        a.showSlots(DUSTBIN);
        a.use(0, a);
        a.use(1, a);
        a.use(2, a);
        a.use(3, a);
        a.use(4, a);
        TEST_NL();
        TEST_LEAKS(3);
    }
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
}

int main()
{
    preliminary_tests();
    return 0;
}