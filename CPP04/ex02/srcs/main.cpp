/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:06:30 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/26 17:47:31 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

typedef enum TAG
{
    INTRODUCE,
    MAKESOUND,
}  e_tag;

static void    animal_show_type(std::string type, e_tag tag)
{
    std::cout << BYELLOW << "[ " << type  << " "  << (tag == INTRODUCE ? "🧐" : "📣") << " ] " << RESET;
}

static void    animal_sample(Animal *animal)
{
    animal_show_type(animal->getType(), INTRODUCE);
    std::cout << animal->getType() << std::endl;
    animal_show_type(animal->getType(), MAKESOUND);
    animal->makeSound();
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
        // ATTENTION: Need to comment out this block to test the rest of the test cases
        // TEST_TITLE("Test 0: Instantiate the abstract class");
        // TEST_DESC("This is to test if the Animal class is instantiable. It should not be.");
        // TEST_DESC("It should not be able to compile.");
        // TEST_NL();

        // Animal animal;
        // (void)animal;
        // Animal *animal2 = new Animal();
        // (void)animal2;
    }
    {
        TEST_TITLE("Test 1: Instantiate the derived class using pointer to the abstract class");
        TEST_DESC("This is to test if the derived class can be instantiated using pointer to the abstract class.");
        TEST_DESC_CONT("Also, to test if the virtual destructor is working.");
        TEST_NL();

        std::cout << BGREEN << "Instantiate a Dog 🐶" << RESET << std::endl;
        Animal *dog = new Dog();
        animal_sample(dog);
        delete dog;
        
        TEST_NL();
        
        std::cout << BGREEN << "Instantiate a Cat 🐱" << RESET << std::endl;
        Animal *cat = new Cat();
        animal_sample(cat);
        delete cat;

        TEST_NL();
        TEST_CONCLUDE("The virtual destructor is working.");
        TEST_CONCLUDE_CONT("Notice that the constructor of the abstract class (Animal) will still be invoked.");
        TEST_CONCLUDE_CONT("The abstract class's constructor is automatically called before the dervied class's constructor,");
        TEST_CONCLUDE_CONT("ensuring that the base class's part of the object is properly initialized before the derived class's");
        TEST_CONCLUDE_CONT("constructor is invoked. The derived class still has access to the members of abstract class (if have).");
        TEST_CONCLUDE_CONT("So, the abstract class's constructor is still needed.");

        TEST_NL();
        TEST_LEAKS(1);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 2: Instantiate the derived class using pointer to derived class.");
        TEST_DESC("If the implementation is correct, it should work as expected.");
        TEST_NL();

        std::cout << BGREEN << "Instantiate a Dog 🐶" << RESET << std::endl;
        Dog *dog = new Dog();
        animal_sample(dog);
        delete dog;
        
        TEST_NL();

        std::cout << BGREEN << "Instantiate a Cat 🐱" << RESET << std::endl;
        Cat *cat = new Cat();
        animal_sample(cat);
        delete cat;

        TEST_NL();
        TEST_LEAKS(2);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 3: Does my brain works?");
        TEST_DESC("Test if the Brain works as expected.");
        TEST_NL();

        TEST_DESC_CONT("Let's try instantiate a cat using its concrete type and a pointer to the concrete class.");
        TEST_DESC_CONT("a. Concrete type:")
        Cat cat1;

        for (int i = 0; i < 5; i++)
            cat1.setIdea(i, GARFIELD_QUOTES[i]);
        show_brain(0, 5, &cat1);

        TEST_HR();

        TEST_DESC_CONT("b. Pointer to concrete class:");
        Cat *cat2 = new Cat();
        
        for (int i = 0; i < 5; i++)
            cat2->setIdea(i, TOM_QUOTES[i]);
        show_brain(0, 5, cat2);
        delete cat2;

        TEST_HR();
        
        TEST_DESC_CONT("Let's try instantiate a dog using pointer to abstract class.");
        Animal *dog1 = new Dog();
        
        for (int i = 0; i < 5; i++)
            dog1->setIdea(i, SNOOPY_QUOTES[i]);
        show_brain(0, 5, dog1);
        delete dog1;

        TEST_HR();
        
        TEST_DESC_CONT("Let's check if brainwashing (deep copy) works:");
        Dog *snoopy = new Dog();

        for (int i = 0; i < 3; i++)
            snoopy->setIdea(i, SNOOPY_QUOTES[i]);
        show_brain(0, 4, snoopy);

        TEST_NL();
        Dog *scooby = new Dog();

        for (int i = 0; i < 3; i++)
            scooby->setIdea(i, SCOOBY_QUOTES[i]);
        show_brain(0, 4, scooby);
        
        *scooby = *snoopy;
        TEST_DESC_CONT("Set a new idea in snoopy's brain. If this idea does not exist in scooby's brain, it means it's a deep copy.");
        snoopy->setIdea(3, SNOOPY_QUOTES[3]);
        show_brain(0, 4, snoopy);
        show_brain(0, 4, scooby);

        delete snoopy;
        delete scooby;

        TEST_LEAKS(3);
        TEST_DESC_CONT("Destrutor of cat1:");
        // Destructor of cat1 will be called after this
    }
}
