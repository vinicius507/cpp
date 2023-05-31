/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:08:53 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:12:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  std::cout << "Default constructor for the Dog class." << std::endl;
}

Dog::Dog(const Dog &other) {
  *this = other;

  std::cout << "Copy constructor for the Dog class." << std::endl;
}

Dog::~Dog(void) { std::cout << "Destructor for the Dog class." << std::endl; }

Dog &Dog::operator=(const Dog &other) {
  this->type = other.type;

  std::cout << "Assignment operator of the Dog class." << std::endl;
  return (*this);
}

void Dog::makeSound(void) const {
  std::cout << this->type << " 🐶: Woof!" << std::endl;
}
