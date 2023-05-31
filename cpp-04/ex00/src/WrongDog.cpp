/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:34:12 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:34:13 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void) : WrongAnimal("WrongDog") {
  std::cout << "Default constructor for the WrongDog class." << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) {
  *this = other;

  std::cout << "Copy constructor for the WrongDog class." << std::endl;
}

WrongDog::~WrongDog(void) {
  std::cout << "Destructor for the WrongDog class." << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
  this->type = other.type;

  std::cout << "Assignment operator of the WrongDog class." << std::endl;
  return (*this);
}

void WrongDog::makeSound(void) const {
  std::cout << this->type << " 🐶: Woof!" << std::endl;
}
