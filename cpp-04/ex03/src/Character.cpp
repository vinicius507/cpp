/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:55:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/07/14 17:01:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character(void) : name("He-Who-Must-Not-Be-Named") {
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    this->inventory[i] = NULL;
  }
}

Character::Character(const std::string &name) : name(name) {
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    this->inventory[i] = NULL;
  }
}

Character::Character(const Character &other) { *this = other; }

Character::~Character(void) {
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (this->inventory[i] != NULL) {
      delete this->inventory[i];
    }
  }
}

Character &Character::operator=(const Character &other) {
  if (this != &other) {
    this->name = other.getName();
    for (int i = 0; i < INVENTORY_SIZE; i++) {
      if (this->inventory[i] != NULL) {
        delete this->inventory[i];
      }
      this->inventory[i] = other.getMateria(i)->clone();
    }
  }
  return (*this);
}

const std::string &Character::getName(void) const { return (this->name); }

AMateria *Character::getMateria(int idx) const {
  if (idx < 0 || idx >= INVENTORY_SIZE) {
    return (NULL);
  }
  return (this->inventory[idx]);
}

void Character::equip(AMateria *m) {
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (this->inventory[i] == NULL) {
      std::cout << "* " << this->getName() << " equips the " << m->getType()
                << " materia *" << std::endl;
      this->inventory[i] = m;
      return;
    }
  }
  std::cerr << "Error: " << this->getName() << " cannot equip the "
            << m->getType() << " materia. The inventory is full." << std::endl;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= INVENTORY_SIZE) {
    std::cerr
        << "Error: cannot unequip materia: inventory index is out of bounds."
        << std::endl;
    return;
  }
  if (this->inventory[idx] == NULL) {
    std::cerr << "Error: " << this->getName()
              << " cannot uneqip unexistent materia." << std::endl;
    return;
  }
  std::cout << "* " << this->getName() << " unequips the "
            << this->inventory[idx]->getType() << " materia *" << std::endl;
  this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  AMateria *materia;

  materia = this->getMateria(idx);
  if (materia == NULL) {
    std::cerr << "Error: there's no materia to use against " << target.getName()
              << "." << std::endl;
    return;
  }
  materia->use(target);
}
