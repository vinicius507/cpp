/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:20:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 15:30:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void) {}

AMateria::AMateria(const std::string &type) {}

AMateria::AMateria(const AMateria &other) { *this = other; }

AMateria::~AMateria(void) {}

AMateria &AMateria::operator=(const AMateria &other) {
  if (this != &other) {
    const_cast<std::string &>(this->type) = other.getType();
  }
  return (*this);
}

const std::string &AMateria::getType(void) const { return (this->type); }

void AMateria::use(ICharacter &target) {
  std::cerr << "Error: AMateria cannot be used against target "
            << target.getName() << "." << std::endl;
}
