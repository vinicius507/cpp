/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:08:53 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/07/17 18:08:59 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  this->brain = new Brain();

  std::cout << "Default constructor for the Dog class." << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog"), brain(new Brain) {
  *this = other;

  std::cout << "Copy constructor for the Dog class." << std::endl;
}

Dog::~Dog(void) {
  if (this->getBrain() != NULL) {
    delete this->brain;
  }

  std::cout << "Destructor for the Dog class." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  *this->brain = *other.getBrain();
  std::cout << "Assignment operator of the Dog class." << std::endl;
  return (*this);
}

Brain *Dog::getBrain() const { return (this->brain); }

void Dog::makeSound(void) const {
  std::cout << this->type << " 🐶: Woof!" << std::endl;
}
