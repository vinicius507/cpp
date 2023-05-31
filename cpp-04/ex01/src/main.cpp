/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:26:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:47:20 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>
#include <iostream>

int main(void) { return (0); }
static void basicSubjectTest(void) {
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  delete j; // should not create a leak
  delete i;
}

int main(void) {
  Animal *animals[NUM_ANIMALS] = {NULL};

  basicSubjectTest();
  return (0);
}
