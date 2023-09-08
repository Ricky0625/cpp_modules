/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:06:30 by wricky-t          #+#    #+#             */
/*   Updated: 2023/09/08 14:49:41 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

typedef enum LIFECYCLE
{
    CONSTRUCT,
    DESTRUCT,
}  e_lifecycle;

static void    show_object_lifecycle(std::string id, e_lifecycle cycle)
{
    if (cycle != CONSTRUCT && cycle != DESTRUCT)
        return ;

    std::cout << id << " ";
    if (cycle == CONSTRUCT)
        std::cout << BGREEN << "construction:" << RESET << std::endl;
    else if (cycle == DESTRUCT)
        std::cout << BRED << "destruction:" << RESET << std::endl;
}

static void show_brain(int start, int end, Animal *animal)
{
    if (start < 0 || end < 0 || start > MAX_IDEA || end > MAX_IDEA)
        return ;
    
    std::cout << animal->getType() << "'s 🧠: " << std::endl;
    if (start < end)
    {
        for (int i = start; i < end; i++)
            std::cout << "  💭["<< i <<"]: " << animal->getIdea(i) << std::endl;
    }
    else
    {
        for (int i = start; i > end; i--)
            std::cout << "  💭["<< i <<"]: " << animal->getIdea(i) << std::endl;
    }
}

int main()
{
    {
        TEST_TITLE("Test 0: Subject test");
        TEST_DESC("Demonstrate the invocation of constructor and destructor");
        TEST_DESC_CONT("Making sure that there's no leaks.");
        TEST_NL();

        show_object_lifecycle("Dog", CONSTRUCT);
        const Animal* i = new Dog();
        TEST_NL();

        show_object_lifecycle("Cat", CONSTRUCT);
        const Animal* j = new Cat();
        TEST_NL();

        show_object_lifecycle("Dog", DESTRUCT);
        delete i; // should not create a leak
        TEST_NL();
        
        show_object_lifecycle("Cat", DESTRUCT);
        delete j;
        TEST_NL();

        TEST_LEAKS(0);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 1: The Animal Shelter");
        TEST_DESC("Create an array of Animal objects. 50% Dog, 50% Cat.");
        TEST_DESC_CONT("Loop over the array and delete every Animal. Should delete them as Animal (through pointer to base class).");
        TEST_NL();
        
        const int   MAX_CAPACITY = 100;
        Animal      *animals[MAX_CAPACITY];
        
        for (int i = 0; i < MAX_CAPACITY; i++)
        {
            std::cout << "[" << i + 1 << "]: ";
            show_object_lifecycle((i % 2 == 0) ? "Dog" : "Cat", CONSTRUCT);
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
            TEST_NL();
        }

        for (int i = 0; i < MAX_CAPACITY; i++)
        {
            std::cout << "[" << i + 1 << "]: ";
            show_object_lifecycle((i % 2 == 0) ? "Dog" : "Cat", DESTRUCT);
            delete animals[i];
            TEST_NL();
        }
        
        TEST_LEAKS(1);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 2: What's on my mind?");
        TEST_DESC("Just to demonstrate that the Brain class is working as intended.");
        TEST_NL();

        Animal *snoopy = new Dog();
        
        for (int i = 0; i < MAX_IDEA; i++)
            snoopy->setIdea(i, SNOOPY_QUOTES[i]);

        show_brain(0, 10, snoopy);
        delete snoopy;
        TEST_NL();
        
        Animal *garfield = new Cat();
        
        for (int i = 0; i < MAX_IDEA; i++)
            garfield->setIdea(i, GARFIELD_QUOTES[i]);
        
        show_brain(0, 10, garfield);
        delete garfield;
        
        TEST_LEAKS(2);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 3: Deep/Shallow copy - Snoopy tries to brainwash Scooby, but will he succeed?");
        TEST_DESC("Trying to demonstrate the invocation of assignment operator on two pointers to base class.");
        TEST_DESC("It calls the base class' assignment operator because the pointers are of type Animal.");
        TEST_NL();
        
        Animal *snoopy = new Dog();

        for (int i = 0; i < MAX_IDEA; i++)
            snoopy->setIdea(i, SNOOPY_QUOTES[i]);

        std::cout << "Snoopy shows his brain:" << std::endl;
        show_brain(0, 5, snoopy);

        TEST_NL();

        Animal *scooby = new Dog();

        for (int i = 0; i < MAX_IDEA; i++)
            scooby->setIdea(i, SCOOBY_QUOTES[i]);

        std::cout << "Scooby shows his brain:" << std::endl;
        show_brain(0, 5, scooby);

        TEST_NL();
        std::cout << "Snoopy's address:" << snoopy << std::endl;
        std::cout << "Snoopy's type address:" << (void*)(snoopy->getType().c_str()) << std::endl;
        std::cout << "Scooby's address:" << scooby << std::endl;
        std::cout << "Scooby's type address:" << (void*)(scooby->getType().c_str()) << std::endl;
        TEST_NL();

        *scooby = *snoopy;
        std::cout << BYELLOW << "OH NO. SNOOPY BRAINWASHED SCOOBY! BUT... IS IT?" << RESET << std::endl;
        
        TEST_NL();
        std::cout << "Snoopy's address:" << snoopy << std::endl;
        std::cout << "Snoopy's type address:" << (void*)snoopy->getType().c_str() << std::endl;
        std::cout << "Scooby's address:" << scooby << std::endl;
        std::cout << "Scooby's type address:" << (void*)scooby->getType().c_str() << std::endl;
        TEST_NL();
        
        std::cout << "Scooby shows his brain again:" << std::endl;
        show_brain(0, 5, scooby);
        std::cout << BYELLOW << "HOORAY! SCOOBY IS STILL SCOOBY!" << RESET << std::endl;
        TEST_NL();

        delete snoopy;
        delete scooby;
        
        TEST_NL();
        TEST_CONCLUDE("Nothing change. This is because we are using pointer to base class and base class does not have access to derived class' Brain.");
        TEST_NL();

        TEST_LEAKS(3);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 4: Deep Copy - Tom & Garfield (Pointers to Derived Class)");
        TEST_DESC("Demonstrate the invocation of assignment operator and make sure that deep copy is performed.");
        TEST_DESC_CONT("Declare the subclasses using pointer to their type (not pointer to base class).");
        TEST_NL();
        
        // TOM
        Cat *tom = new Cat();

        for (int i = 0; i < 3; i++)
            tom->setIdea(i, TOM_QUOTES[i]);

        std::cout << "Tom shows his brain:" << std::endl;
        show_brain(0, 3, tom);

        TEST_NL();

        // GARFIELD
        Cat *garfield = new Cat();

        for (int i = 0; i < 2; i++)
            garfield->setIdea(i, GARFIELD_QUOTES[i]);

        std::cout << "Garfield shows his brain:" << std::endl;
        show_brain(0, 3, garfield);

        // GARFIELD BRAINWASHES TOM
        *tom = *garfield;

        // set another idea for garfield. if tom's brain does not have this idea, meaning deep copy is successful.
        // deep copy means it will copy the content of the pointer to the new pointer, not the address.
        // if it's a shallow copy, meaning tom's brain will point to garfield's brain, which also means the new idea will appear is tom's brain.
        garfield->setIdea(2, GARFIELD_QUOTES[2]);
        
        std::cout << BYELLOW << "OH NO. GARFIELD BRAINWASHED TOM! BUT... IS IT?" << RESET << std::endl;
        std::cout << "Tom shows his brain:" << std::endl;
        show_brain(0, 3, tom);
        TEST_NL();
        std::cout << "Garfield shows his brain:" << std::endl;
        show_brain(0, 3, garfield);
        std::cout << BYELLOW << "TOM WILL NOW THINK LIKE GARFIELD!" << RESET << std::endl;

        TEST_NL();
        delete tom;
        delete garfield;

        TEST_LEAKS(4);   
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 5: Deep Copy - Tom & Garfield (Create object on stack, concrete instance)");
        TEST_DESC("Demonstrate the invocation of assignment operator and make sure that deep copy is performed.");
        TEST_NL();

        Cat tom;
        
        for (int i = 0; i < 3; i++)
            tom.setIdea(i, TOM_QUOTES[i]);

        std::cout << "Tom shows his brain:" << std::endl;
        show_brain(0, 3, &tom);

        TEST_NL();

        Cat garfield;

        for (int i = 0; i < 2; i++)
            garfield.setIdea(i, GARFIELD_QUOTES[i]);

        std::cout << "Garfield shows his brain:" << std::endl;
        show_brain(0, 3, &garfield);

        // GARFIELD BRAINWASHES TOM
        tom = garfield;
        // Prove that it's a deep copy
        garfield.setIdea(2, GARFIELD_QUOTES[2]);

        std::cout << BYELLOW << "OH NO. GARFIELD BRAINWASHED TOM! BUT... IS IT?" << RESET << std::endl;
        std::cout << "Tom shows his brain:" << std::endl;
        show_brain(0, 3, &tom);
        TEST_NL();
        std::cout << "Garfield shows his brain:" << std::endl;
        show_brain(0, 3, &garfield);
        std::cout << BYELLOW << "TOM WILL NOW THINK LIKE GARFIELD!" << RESET << std::endl;
        
        TEST_NL();
        // no need to delete, because it's on the stack and it will be freed when out of this scope.
        // NOTE: the destructor will be called after TEST_LEAKS because that line of code is still in this scope.
        TEST_LEAKS(5);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 6: Deep Copy - Snoopy & Scooby (Pointers to Derived Class)");
        TEST_DESC("Demonstrate the invocation of copy constructor and make sure that deep copy is performed.");
        TEST_NL();

        Dog *snoopy = new Dog();

        for (int i = 0; i < 3; i++)
            snoopy->setIdea(i, SNOOPY_QUOTES[i]);

        std::cout << "Snoopy shows his brain:" << std::endl;
        show_brain(0, 3, snoopy);

        // Copy constructor: create a copy of snoopy
        Dog *scooby = new Dog(*snoopy);

        // set another idea in snoopy's brain again to prove that deep copy is performed
        snoopy->setIdea(4, SNOOPY_QUOTES[4]);
        
        std::cout << "Scooby shows his brain:" << std::endl;
        show_brain(0, 5, scooby);

        std::cout << "Snoopy shows his brain:" << std::endl;
        show_brain(0, 5, snoopy);

        TEST_NL();
        TEST_LEAKS(6);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 7: Deep Copy - Snoopy & Scooby (Create concrete instance)");
        TEST_DESC("Demonstrate the invocation of copy constructor and make sure that deep copy is performed.");
        TEST_NL();

        Dog snoopy;

        for (int i = 0; i < 3; i++)
            snoopy.setIdea(i, SNOOPY_QUOTES[i]);

        std::cout << "Snoopy shows his brain:" << std::endl;
        show_brain(0, 3, &snoopy);

        // Copy constructor: create a copy of snoopy
        Dog scooby(snoopy);

        // set another idea in snoopy's brain again to prove that deep copy is performed
        snoopy.setIdea(4, SNOOPY_QUOTES[4]);
        
        std::cout << "Scooby shows his brain:" << std::endl;
        show_brain(0, 5, &scooby);

        std::cout << "Snoopy shows his brain:" << std::endl;
        show_brain(0, 5, &snoopy);

        TEST_NL();
        TEST_LEAKS(7);
    }
}
