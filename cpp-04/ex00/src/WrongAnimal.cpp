/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:18:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:20:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) {
  std::cout << "Default constructor of the WrongAnimal class." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string _type) : type(_type) {
  std::cout << "Parametrized constructor of the WrongAnimal class."
            << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  *this = other;

  std::cout << "Copy constructor of the WrongAnimal class." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "Destructor of the WrongAnimal class." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  this->type = other.getType();

  std::cout << "Assignment operator of the WrongAnimal class." << std::endl;
  return (*this);
}

std::string WrongAnimal::getType(void) const { return (this->type); }

void WrongAnimal::makeSound() const {
  std::cout << "The WrongAnimal makes an unknown sound." << std::endl;
}
