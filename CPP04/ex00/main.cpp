/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:03:52 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/03 19:21:05 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    // Provided tests for correct polymorphism
    std::cout << "--- TESTING POLYMORPHISM ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- TESTING WRONG POLYMORPHISM ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat(); // Pointer to base, object of derived

    std::cout << wrongI->getType() << " " << std::endl;
    wrongI->makeSound(); // Will output WrongAnimal sound because makeSound is not virtual
    wrongMeta->makeSound();

    // To explicitly call WrongCat's sound (not polymorphic)
    const WrongCat* actualWrongCat = new WrongCat();
    actualWrongCat->makeSound();

    delete wrongMeta;
    delete wrongI;
    delete actualWrongCat;

    std::cout << "\n--- ADDITIONAL TESTS ---" << std::endl;
    // Test copy constructor and assignment operator
    std::cout << "\nTesting Dog copy and assignment:" << std::endl;
    Dog dog1;
    Dog dog2 = dog1; // Copy constructor
    Dog dog3;
    dog3 = dog1;     // Assignment operator
    dog1.makeSound();
    dog2.makeSound();
    dog3.makeSound();

    std::cout << "\nTesting Cat copy and assignment:" << std::endl;
    Cat cat1;
    Cat cat2 = cat1; // Copy constructor
    Cat cat3;
    cat3 = cat1;     // Assignment operator
    cat1.makeSound();
    cat2.makeSound();
    cat3.makeSound();

    // Array of Animals
    std::cout << "\nTesting array of Animals (polymorphic behavior in loop):" << std::endl;
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int k = 0; k < 4; ++k) {
        std::cout << animals[k]->getType() << " says: ";
        animals[k]->makeSound();
    }

    for (int k = 0; k < 4; ++k) {
        delete animals[k];
    }

    return 0;
}