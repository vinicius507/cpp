/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:31:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 13:47:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
  std::cout << "Default constructor of the Animal class." << std::endl;
}

Animal::Animal(const std::string _type) : type(_type) {
  std::cout << "Parametrized constructor of the Animal class." << std::endl;
}

Animal::Animal(const Animal &other) {
  *this = other;

  std::cout << "Copy constructor of the Animal class." << std::endl;
}

Animal::~Animal(void) {
  std::cout << "Destructor of the Animal class." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  this->type = other.getType();

  std::cout << "Assignment operator of the Animal class." << std::endl;
  return (*this);
}

std::string Animal::getType(void) const { return (this->type); }

void Animal::makeSound() const {
  std::cout << "The Animal makes an unknown sound." << std::endl;
}
