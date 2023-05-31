/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:26:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 15:44:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>
#include <iostream>

#define NUM_ANIMALS 10
#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " << #TEST_CASE << std::endl;                          \
    TEST_CASE();                                                               \
    std::cout << std::setw(32) << std::setfill('-') << "" << std::endl;        \
  } while (0)

static void populateDogs(AAnimal **animals) {
  for (int i = 0; i < NUM_ANIMALS / 2; i++) {
    animals[i] = new Dog();
  }
}

static void populateCats(AAnimal **animals) {
  for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; i++) {
    animals[i] = new Cat();
  }
}

static void basicSubjectTest(void) {
  const AAnimal *j = new Dog();
  const AAnimal *i = new Cat();

  delete j; // should not create a leak
  delete i;
}

static void extendedSubjectTest(void) {
  AAnimal *animals[NUM_ANIMALS] = {NULL};

  populateDogs(animals);
  populateCats(animals);
  for (int i = 0; i < NUM_ANIMALS; i++) {
    delete animals[i];
  }
}

static void printIdeas(Brain *brain) {
  int i = 0;
  std::string idea;

  if (brain == NULL)
    return;
  while (i < 100 && (idea = brain->getIdea(i)) != "") {
    std::cout << "Idea #" << i << ": " << idea << "(" << &idea << ")"
              << std::endl;
    i++;
  }
}

static void deepCopyTest(void) {
  Cat cat;
  Cat catCopy;
  Brain *brain;

  brain = cat.getBrain();
  brain->newIdea("This is a common idea");
  catCopy = cat;
  brain = catCopy.getBrain();
  brain->newIdea("Unique idea");
  brain = cat.getBrain();
  printIdeas(cat.getBrain());
  printIdeas(catCopy.getBrain());
}

int main(void) {
  TEST(basicSubjectTest);
  TEST(extendedSubjectTest);
  TEST(deepCopyTest);
  return (0);
}
