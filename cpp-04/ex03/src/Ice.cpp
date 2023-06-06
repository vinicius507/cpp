/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 16:51:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &other) { *this = other; }

Ice::~Ice(void) {}

Ice &Ice::operator=(const Ice &other) {
  (void)other;
  return (*this);
}

AMateria *Ice::clone(void) const {
  Ice *clone;

  clone = new Ice(*this);
  return (clone);
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
