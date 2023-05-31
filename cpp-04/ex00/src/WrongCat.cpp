/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:26:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:26:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << "Default constructor for the WrongCat class." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
  *this = other;

  std::cout << "Copy constructor for the WrongCat class." << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "Destructor for the WrongCat class." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  this->type = other.type;

  std::cout << "Assignment operator of the WrongCat class." << std::endl;
  return (*this);
}

void WrongCat::makeSound(void) const {
  std::cout << this->type << " 🐱: Meoww" << std::endl;
}
