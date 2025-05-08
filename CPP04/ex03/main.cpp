/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:49:26 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/08 14:51:38 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void run_provided_tests() {
    std::cout << "--- RUNNING PROVIDED TESTS ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp); // `me` now owns `tmp` if equipped
    // If not equipped, `tmp` would leak unless deleted here.

    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Test equipping more than 4 materias (should not crash, extra materias might be ignored or lead to leaks if not handled)
    AMateria* extra_ice = src->createMateria("ice");
    me->equip(extra_ice); // equip 3rd
    AMateria* extra_cure = src->createMateria("cure");
    me->equip(extra_cure); // equip 4th
    AMateria* overflow_materia = src->createMateria("ice");
    me->equip(overflow_materia); // Try to equip 5th, should do nothing to inventory
    delete overflow_materia; // IMPORTANT: if equip fails, created materia must be deleted by caller

    ICharacter* bob = new Character("bob");

    std::cout << "\n--- ME USING MATERIAS ON BOB ---" << std::endl;
    me->use(0, *bob); // Use ice
    me->use(1, *bob); // Use cure
    me->use(2, *bob); // Use extra_ice
    me->use(3, *bob); // Use extra_cure
    me->use(4, *bob); // Try to use non-existent materia (slot 4)

    std::cout << "\n--- CLEANUP ---" << std::endl;
    delete bob;
    delete me;
    delete src;
    std::cout << "--- PROVIDED TESTS COMPLETED ---" << std::endl;
}

void run_deep_copy_tests() {
    std::cout << "\n--- TESTING DEEP COPY FOR CHARACTER AND MATERIASOURCE ---" << std::endl;

    // MateriaSource copy
    IMateriaSource* src1 = new MateriaSource();
    src1->learnMateria(new Ice());
    src1->learnMateria(new Cure());

    IMateriaSource* src2 = new MateriaSource(*(static_cast<MateriaSource*>(src1))); // Copy constructor
    // Delete src1 to see if src2 still works (proves deep copy of learned materias)
    // delete src1; // If src1 is deleted, and src2 used its pointers, src2 would fail.
                // With deep copy, src2 has its own cloned materias.

    // Character copy
    Character* char1 = new Character("char1");
    AMateria* ice_clone = src2->createMateria("ice"); // src2 should still work after src1 deleted if deep copy worked
    if (ice_clone) char1->equip(ice_clone);

    Character* char2 = new Character(*char1); // Copy constructor for Character
    std::cout << char1->getName() << " uses materia on " << char2->getName() << ":" << std::endl;
    char1->use(0, *char2);
    std::cout << char2->getName() << " uses materia on " << char1->getName() << " (should be the same type if deep copy worked):" << std::endl;
    char2->use(0, *char1); // char2 should have its own clone of the materia

    // Change materia in char1 (if possible, or unequip and equip new)
    // to show char2 is unaffected.
    char1->unequip(0); // Materia is now "on the floor", need to delete ice_clone
    delete ice_clone; // The unequipped materia needs to be deleted
    
    AMateria* cure_clone_for_char1 = src2->createMateria("cure");
    if (cure_clone_for_char1) char1->equip(cure_clone_for_char1);
    
    std::cout << char1->getName() << " now uses new materia:" << std::endl;
    char1->use(0, *char2);
    std::cout << char2->getName() << " still uses original materia:" << std::endl;
    char2->use(0, *char1); // Should still be ice

    // Test assignment operator for Character
    Character* char3 = new Character("char3");
    *char3 = *char1; // Assignment operator
    std::cout << char3->getName() << " (assigned from char1) uses materia:" << std::endl;
    char3->use(0, *char2);


    // Cleanup for deep copy tests
    delete char1; // Will delete its materias (cure_clone_for_char1)
    delete char2; // Will delete its materias (the original ice clone's clone)
    delete char3; // Will delete its materias (clone of cure_clone_for_char1)
    delete src1;  // Deletes its learned Ice and Cure originals
    delete src2;  // Deletes its *clones* of Ice and Cure
                  // This part requires MateriaSource destructor to delete its _learnedMaterias.
                  // And the assignment/copy constructor of MateriaSource to deep copy (clone) the materias it learns.

    std::cout << "--- DEEP COPY TESTS COMPLETED ---" << std::endl;
}

void unequip_tests() {
    std::cout << "\n--- TESTING UNEQUIP ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    ICharacter* player = new Character("Player");
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("ice");

    player->equip(m1);
    player->equip(m2);
    player->use(0, *player);
    player->use(1, *player);

    player->unequip(0); // m1 is now on the "floor"
    std::cout << "Player used slot 0 after unequip (should do nothing or error):" << std::endl;
    player->use(0, *player); // Should not work for slot 0
    std::cout << "Player used slot 1 after unequip (should still work):" << std::endl;
    player->use(1, *player); // Slot 1 should still have m2

    // The unequipped materia m1 must be handled (e.g., deleted)
    std::cout << "Deleting unequipped materia m1 manually." << std::endl;
    delete m1; // [cite: 86] - "Handle the Materias your character leaves on the floor as you like... don’t forget that you have to avoid memory leaks."

    delete player; // This will delete m2
    delete src;
    std::cout << "--- UNEQUIP TESTS COMPLETED ---" << std::endl;
}


int main() {
    run_provided_tests();
    run_deep_copy_tests();
    unequip_tests();

    // Additional tests for MateriaSource learning limits
    std::cout << "\n--- TESTING MATERIASOURCE LEARNING LIMITS ---" << std::endl;
    IMateriaSource* limited_src = new MateriaSource();
    AMateria* ice1 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* ice2 = new Ice();
    AMateria* cure2 = new Cure();
    AMateria* ice3_overflow = new Ice(); // This one should not be learned or should be deleted by learnMateria

    limited_src->learnMateria(ice1);
    limited_src->learnMateria(cure1);
    limited_src->learnMateria(ice2);
    limited_src->learnMateria(cure2);
    std::cout << "Attempting to learn a 5th materia (should be ignored or materia deleted by learnMateria):" << std::endl;
    limited_src->learnMateria(ice3_overflow); // ice3_overflow should be deleted by learnMateria if it can't store it.

    // Test creating materias from limited_src
    AMateria* test_m = limited_src->createMateria("ice");
    if (test_m) std::cout << "Created from limited_src: " << test_m->getType() << std::endl;
    delete test_m;
    test_m = limited_src->createMateria("cure");
    if (test_m) std::cout << "Created from limited_src: " << test_m->getType() << std::endl;
    delete test_m;
    test_m = limited_src->createMateria("unknown");
    if (!test_m) std::cout << "Correctly failed to create unknown materia from limited_src." << std::endl;
    // No need to delete test_m here as it would be NULL.

    delete limited_src; // This will delete ice1, cure1, ice2, cure2. ice3_overflow should have been deleted by learnMateria.

    std::cout << "\nAll tests finished." << std::endl;
    return 0;
}
