/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:26:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:28:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
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

  meta->makeSound();

  delete meta;
}

int main(void) {
  subjectExample();
  wrongExample();
  return (0);
}
