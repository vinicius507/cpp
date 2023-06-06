/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:43:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 16:52:07 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("ice") {}

Cure::Cure(const Cure &other) { *this = other; }

Cure::~Cure(void) {}

Cure &Cure::operator=(const Cure &other) {
  (void)other;
  return (*this);
}

AMateria *Cure::clone(void) const {
  Cure *clone;

  clone = new Cure(*this);
  return (clone);
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *'" << std::endl;
}
