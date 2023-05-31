/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:26:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:38:37 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>

static void subjectExample(void) {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete i;
  delete j;
  delete meta;
}

static void wrongExample(void) {
  const WrongAnimal *meta = new WrongAnimal();
  const WrongAnimal *j = new WrongDog();
  const WrongAnimal *i = new WrongCat();

  std::cout << i->getType() << std::endl;
  std::cout << j->getType() << std::endl;
  j->makeSound();
  i->makeSound();
  meta->makeSound();

  delete i;
  delete meta;
}

static void additionalTests(void) {
  Cat cat;
  Cat wrongCat;
  Animal catCopy = Cat();
  WrongAnimal wrongCatCopy = WrongCat();

  std::cout << cat.getType() << std::endl
            << wrongCat.getType() << std::endl
            << catCopy.getType() << std::endl
            << wrongCatCopy.getType() << std::endl;
  cat.makeSound();
  wrongCat.makeSound();
  catCopy.makeSound();
  wrongCatCopy.makeSound();
}

int main(void) {
  subjectExample();
  wrongExample();
  additionalTests();
  return (0);
}
