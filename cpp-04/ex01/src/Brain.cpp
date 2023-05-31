/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:56:46 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 15:01:52 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
  std::cout << "Constructor for the Brain class." << std::endl;
}

Brain::Brain(const Brain &other) {
  *this = other;

  std::cout << "Copy constructor for the Brain class." << std::endl;
}

Brain::~Brain(void) {
  std::cout << "Destructor for the Brain class." << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = other.getIdea(i);
  }

  std::cout << "Assignment operator for the Brain class." << std::endl;
  return (*this);
}

std::string Brain::getIdea(const unsigned int index) const {
  if (index > 100) {
    return ("");
  }
  return (this->ideas[index]);
}

void Brain::newIdea(std::string idea) {
  static int i;

  this->ideas[i] = idea;
  i = (i + 1) % 100;
}
