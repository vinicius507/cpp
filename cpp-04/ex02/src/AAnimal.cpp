/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:31:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 15:45:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) {
  std::cout << "Default constructor of the AAnimal class." << std::endl;
}

AAnimal::AAnimal(const std::string _type) : type(_type) {
  std::cout << "Parametrized constructor of the AAnimal class." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
  *this = other;

  std::cout << "Copy constructor of the AAnimal class." << std::endl;
}

AAnimal::~AAnimal(void) {
  std::cout << "Destructor of the AAnimal class." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
  this->type = other.getType();

  std::cout << "Assignment operator of the AAnimal class." << std::endl;
  return (*this);
}

std::string AAnimal::getType(void) const { return (this->type); }

void AAnimal::makeSound() const {
  std::cout << "The AAnimal makes an unknown sound." << std::endl;
}
