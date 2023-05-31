/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:38:46 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 15:16:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  this->brain = new Brain();

  std::cout << "Default constructor for the Cat class." << std::endl;
}

Cat::Cat(const Cat &other) {
  *this = other;

  std::cout << "Copy constructor for the Cat class." << std::endl;
}

Cat::~Cat(void) {
  delete this->brain;

  std::cout << "Destructor for the Cat class." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  this->type = other.type;
  this->brain = new Brain(*other.getBrain());

  std::cout << "Assignment operator of the Cat class." << std::endl;
  return (*this);
}

Brain *Cat::getBrain(void) const { return (this->brain); }

void Cat::makeSound(void) const {
  std::cout << this->type << " 🐱: Meoww" << std::endl;
}
