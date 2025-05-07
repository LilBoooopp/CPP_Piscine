/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:44:42 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 21:49:44 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main() {
    std::cout << "--- EXERCISE 02: TESTING ABSTRACT ANIMAL CLASS ---" << std::endl;

    // const AAnimal* meta = new AAnimal(); // This line will now cause a COMPILE ERROR!
    // std::cout << "Attempting to instantiate Animal directly (should fail compilation)." << std::endl;

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << "\nAnimal pointer (Dog) type: " << j->getType() << std::endl;
    j->makeSound();

    std::cout << "\nAnimal pointer (Cat) type: " << i->getType() << std::endl;
    i->makeSound();

    delete j;
    delete i;

    std::cout << "\n--- TESTING ARRAY OF ANIMALS (STILL WORKS) ---" << std::endl;
    const int num_animals = 2;
    AAnimal* animals[num_animals];

    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int k = 0; k < num_animals; ++k) {
        if (animals[k]) { // Good practice to check pointer
            std::cout << "Type: " << animals[k]->getType() << ", Sound: ";
            animals[k]->makeSound();
            delete animals[k];
            animals[k] = NULL; // Avoid dangling pointer
        }
    }

    // Test Dog and Cat directly (if needed for other tests)
    std::cout << "\n--- Direct instantiation of Dog and Cat ---" << std::endl;
    Dog myDog;
    Cat myCat;
    myDog.makeSound();
    myCat.makeSound();
    // myDog and myCat will be destructed automatically when they go out of scope.

    std::cout << "\nEnd of Exercise 02 tests." << std::endl;
    return 0;
}
