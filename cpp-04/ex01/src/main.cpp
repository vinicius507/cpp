/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:26:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 15:32:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>
#include <iostream>

#define NUM_ANIMALS 10

static void populateDogs(Animal **animals) {
  for (int i = 0; i < NUM_ANIMALS / 2; i++) {
    animals[i] = new Dog();
  }
}

static void populateCats(Animal **animals) {
  for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; i++) {
    animals[i] = new Cat();
  }
}

static void basicSubjectTest(void) {
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  delete j; // should not create a leak
  delete i;
}

static void extendedSubjectTest(void) {
  Animal *animals[NUM_ANIMALS] = {NULL};

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
  basicSubjectTest();
  extendedSubjectTest();
  deepCopyTest();
  return (0);
}
