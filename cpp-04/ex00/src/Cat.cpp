/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:38:46 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:11:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  std::cout << "Default constructor for the Cat class." << std::endl;
}

Cat::Cat(const Cat &other) {
  *this = other;

  std::cout << "Copy constructor for the Cat class." << std::endl;
}

Cat::~Cat(void) { std::cout << "Destructor for the Cat class." << std::endl; }

Cat &Cat::operator=(const Cat &other) {
  this->type = other.type;

  std::cout << "Assignment operator of the Cat class." << std::endl;
  return (*this);
}

void Cat::makeSound(void) const {
  std::cout << this->type << " 🐱: Meoww" << std::endl;
}
