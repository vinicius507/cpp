/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:26:55 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 16:57:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
  for (int i = 0; i < MAX_BASE_MATERIAS; i++) {
    this->baseMaterias[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource &other) { *this = other; }

MateriaSource::~MateriaSource(void) {
  for (int i = 0; i < MAX_BASE_MATERIAS; i++) {
    if (this->getBaseMateria(i) != NULL) {
      delete this->baseMaterias[i];
    }
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  AMateria *materia;

  if (this != &other) {
    for (int i = 0; i < MAX_BASE_MATERIAS; i++) {
      if (this->getBaseMateria(i) != NULL) {
        delete this->baseMaterias[i];
        this->baseMaterias[i] = NULL;
      }
      if ((materia = other.getBaseMateria(i)) != NULL) {
        this->baseMaterias[i] = materia->clone();
      }
    }
  }
  return (*this);
}

AMateria *MateriaSource::getBaseMateria(int idx) const {
  if (idx < 0 || idx >= MAX_BASE_MATERIAS) {
    return (NULL);
  }
  return (this->baseMaterias[idx]);
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < MAX_BASE_MATERIAS; i++) {
    if ((this->getBaseMateria(i) == NULL)) {
      this->baseMaterias[i] = m;
      std::cout << "* the MateriaSource learnt how to clone the "
                << m->getType() << " materia *" << std::endl;
      return;
    }
  }
  std::cerr << "Error: the MateriaSource materia base is full." << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  AMateria *materia;

  for (int i = 0; i < MAX_BASE_MATERIAS; i++) {
    materia = this->getBaseMateria(i);
    if (materia != NULL && materia->getType() == type) {
      std::cout << "* the MateriaSource created a materia of type " << type
                << " *" << std::endl;
      return (materia->clone());
    }
  }
  std::cerr << "Error: the MateriaSource can't create the unknown materia "
            << type << "." << std::endl;
  return (NULL);
}
