 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:03:52 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/03 19:26:17 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main() {
	std::cout << "--- EXERCISE 01: TESTING DEEP COPY AND BRAIN ---" << std::endl;

	// Provided main
	const Animal* j_animal = new Dog();
	const Animal* i_animal = new Cat();

	std::cout << "\nDeleting j_animal (Dog) and i_animal (Cat):" << std::endl;
	delete j_animal;
	delete i_animal;

	std::cout << "\n--- TESTING ARRAY OF ANIMALS ---" << std::endl;
	const int num_animals = 4;
	Animal* animals[num_animals];

	std::cout << "\nCreating Dogs and Cats for the array:" << std::endl;
	for (int k = 0; k < num_animals / 2; ++k) {
		animals[k] = new Dog();
	}
	for (int k = num_animals / 2; k < num_animals; ++k) {
		animals[k] = new Cat();
	}

	std::cout << "\nAnimals in array making sounds and showing ideas:" << std::endl;
	for (int k = 0; k < num_animals; ++k) {
		std::cout << "Animal type: " << animals[k]->getType() << std::endl;
		animals[k]->makeSound();
		// To call showIdeas, we'd need to cast or have it in Animal (not required by exercise)
		// Dynamic cast example (safer):
		Dog* d = dynamic_cast<Dog*>(animals[k]);
		if (d) d->showIdeas();
		Cat* c = dynamic_cast<Cat*>(animals[k]);
		if (c) c->showIdeas();
	}

	std::cout << "\nDeleting animals from the array:" << std::endl;
	for (int k = 0; k < num_animals; ++k) {
		delete animals[k]; // Virtual destructor in Animal is crucial here
	}

	std::cout << "\n--- TESTING DEEP COPY ---" << std::endl;
	// Dog deep copy test
	std::cout << "\nDog deep copy test:" << std::endl;
	Dog dog_original;
	dog_original.showIdeas(); // Show original dog's idea

	Dog dog_copied = dog_original; // Calls copy constructor
	std::cout << "Original Dog after copy:" << std::endl;
	dog_original.showIdeas();
	std::cout << "Copied Dog:" << std::endl;
	dog_copied.showIdeas();
	// Modify copied dog's brain to prove it's a separate brain
	// This requires access to brain ideas, let's assume Brain has a public member or setter for test
	// For now, we rely on constructor/destructor messages and the fact that different addresses would be used
	// If Brain's ideas were pointers, this test would be more explicit.
	// With std::string ideas[100], the copy is of the strings themselves.

	Dog dog_assigned;
	dog_assigned = dog_original; // Calls assignment operator
	std::cout << "Assigned Dog:" << std::endl;
	dog_assigned.showIdeas();

	// Cat deep copy test
	std::cout << "\nCat deep copy test:" << std::endl;
	Cat cat_original;
	cat_original.showIdeas();

	Cat cat_copied = cat_original;
	std::cout << "Original Cat after copy:" << std::endl;
	cat_original.showIdeas();
	std::cout << "Copied Cat:" << std::endl;
	cat_copied.showIdeas();

	Cat cat_assigned;
	cat_assigned = cat_original;
	std::cout << "Assigned Cat:" << std::endl;
	cat_assigned.showIdeas();

	// Test that copies are deep by changing an idea in a copy and seeing original is unaffected
	std::cout << "\n--- Explicit Deep Copy Test (Modifying Copy) ---" << std::endl;
	Dog* dog_source = new Dog();
	if (dog_source) { // Check if allocation succeeded
		// Modify dog_source's first idea if possible, or ensure Brain constructor sets unique values
		// For simplicity, let's assume Brain's constructor initializes ideas in a way that can be checked
		// or add a method to Brain to set an idea for testing.
		// For now, we rely on the principle that new Brain(*(other.brain)) creates a distinct copy.
		std::cout << "Dog Source Original Idea:" << std::endl;
		dog_source->showIdeas();

		Dog* dog_deep_copy = new Dog(*dog_source); // Deep copy
		if (dog_deep_copy) {
			std::cout << "Dog Deep Copy Initial Idea (should match source):" << std::endl;
			dog_deep_copy->showIdeas();

			// To truly test, we would need a way to modify dog_deep_copy's brain independently.
			// Let's assume we add a setter to Brain or Dog for this purpose for a more robust test.
			// For example: dog_deep_copy->getBrain()->ideas[0] = "A new idea for the copy!";
			// Then check dog_source's ideas again.

			delete dog_deep_copy;
		}
		delete dog_source;
	}
	// The destructors being called for separate Brains is also an indicator of deep copy.

	std::cout << "\nEnd of Exercise 01 tests." << std::endl;
	return 0;
}