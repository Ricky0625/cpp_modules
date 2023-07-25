/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:06:30 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 14:50:56 by wricky-t         ###   ########.fr       */
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

void    animal_show_type(std::string type, e_tag tag)
{
    std::cout << BYELLOW << "[ " << type  << " "  << (tag == INTRODUCE ? "🧐" : "📣") << " ] " << RESET;
}

void    animal_sample(Animal *animal)
{
    animal_show_type(animal->getType(), INTRODUCE);
    std::cout << animal->getType() << std::endl;
    animal_show_type(animal->getType(), MAKESOUND);
    animal->makeSound();
}

void    wrong_animal_sample(WrongAnimal *wanimal)
{
    animal_show_type(wanimal->getType(), INTRODUCE);
    std::cout << wanimal->getType() << std::endl;
    animal_show_type(wanimal->getType(), MAKESOUND);
    wanimal->makeSound();
}

int main()
{
    {
        TEST_TITLE("Test 0: Subject's Test");
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        j->makeSound();
        i->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
        std::cout << std::endl;
        TEST_LEAKS(0);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 1: Base Class");

        Animal *animal = new Animal();
        animal_sample(animal);
        
        delete animal;
        std::cout << std::endl;
        TEST_LEAKS(1);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 2: Derived Classes");
        TEST_DESC("This test is to observe how each derived class's constructor, destructor is invoked.");
        TEST_DESC_CONT("Notice that when destructing a derived class object, the derived class's destructor is called first then the base class's destructor.");
        TEST_DESC_CONT("This is achieved by using the `virtual` keyword in the base class's destructor.");
        TEST_DESC_CONT("Without this virtual destructor, we may have issues when deleting objects through a base class pointer.");
        std::cout << std::endl;

        Dog *dog = new Dog();
        Cat *cat = new Cat();
        
        std::cout << "dog's type: " << dog->getType() << std::endl;
        std::cout << "cat's type: " << cat->getType() << std::endl;
        dog->makeSound();
        cat->makeSound();

        delete dog;
        delete cat;
        std::cout << std::endl;
        TEST_LEAKS(2);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 3: Subtype Polymorphism");
        TEST_DESC("This test is to observe how each derived class's implementation is invoked due to polymorphism.");
        TEST_DESC_CONT("Notice that the correct `makeSound()` function of each derived class is called based on their actual type.");
        std::cout << std::endl;

        Animal *animals[3];
        animals[0] = new Animal();
        animals[1] = new Dog();
        animals[2] = new Cat();

        for (int i = 0; i < 3; i++)
            animal_sample(animals[i]);

        // delete[] is for deleting arrays of objects, not arays of pointers
        for (int i = 0; i < 3; i++)
            delete animals[i];
        std::cout << std::endl;
        TEST_LEAKS(3);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 4: WrongAnimal base class");
        std::cout << std::endl;

        WrongAnimal *wrongAnimal = new WrongAnimal();

        wrong_animal_sample(wrongAnimal);
        delete wrongAnimal;
        std::cout << std::endl;
        TEST_LEAKS(4);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 5: WrongAnimal derived classes");
        TEST_DESC("Everything should work as expected here, wrongCat will call its implementation of `makeSound()`");
        TEST_DESC_CONT("This is because we are calling it through a pointer of its actual type.");
        TEST_DESC_CONT("The behavior of the destructors is also as expected. Derived class destructor then the base class destructor.");
        std::cout << std::endl;

        WrongCat *wrongCat = new WrongCat();

        std::cout << "wrongCat's type: " << wrongCat->getType() << std::endl;
        wrongCat->makeSound();
        delete wrongCat;
        std::cout << std::endl;
        TEST_LEAKS(5);
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 6: WrongAnimal's subtype polymorphism? (not really)");
        TEST_DESC("This test case is somewhat similar to Test 5. The difference between them is that we are calling `makeSound()` through a base class pointer.");
        TEST_DESC_CONT("And since that function is not virtual, the base class's implementation of `makeSound()` is called instead.");
        TEST_DESC_CONT("Notice that this time, only the destructor of the base class is called.");
        TEST_DESC_CONT("This is because the derived class's destructor is not virtual.");
        TEST_DESC_CONT("Even though there's no leak, but image we have dynamic memory allocated in WrongCat's object. That would be a memory leak.");
        std::cout << std::endl;

        WrongAnimal *wrongCat = new WrongCat();

        wrong_animal_sample(wrongCat);
        delete wrongCat;
        std::cout << std::endl;
        TEST_LEAKS(6);
    }
}
