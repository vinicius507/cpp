/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:26:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 15:21:48 by vgoncalv         ###   ########.fr       */
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

int main(void) {
  basicSubjectTest();
  extendedSubjectTest();
  return (0);
}
