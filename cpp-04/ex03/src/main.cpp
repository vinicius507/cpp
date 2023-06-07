/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:51:50 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 18:00:07 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iomanip>
#include <iostream>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " << #TEST_CASE << std::endl;                          \
    TEST_CASE();                                                               \
    std::cout << std::setw(32) << std::setfill('-') << "" << std::endl;        \
  } while (0)

static void subjectTests(void) {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
}

static void iceMateriaTests(void) {
  AMateria *ice;
  AMateria *clone;
  Character target("Bob");

  ice = new Ice;
  ice->use(target);
  clone = ice->clone();
  std::cout << "&ice=" << &ice << " &clone=" << &clone << std::endl;
  clone->use(target);
  delete ice;
  delete clone;
}

static void cureMateriaTests(void) {
  AMateria *cure;
  AMateria *clone;
  Character target("Bob");

  cure = new Cure;
  cure->use(target);
  clone = cure->clone();
  std::cout << "&cure=" << &cure << " &clone=" << &clone << std::endl;
  clone->use(target);
  delete cure;
  delete clone;
}

static void characterTests(void) {
  Ice *ice = new Ice;
  Cure *cure = new Cure;
  AMateria *iceClone = ice->clone();
  AMateria *cureClone = cure->clone();

  ICharacter *character;
  ICharacter *target;

  character = new Character("Marvin");
  target = new Character("Bob");

  std::cout << character->getName() << " " << &character << std::endl
            << target->getName() << " " << &target << std::endl;

  character->equip(ice);
  target->equip(cure);
  character->use(0, *target);
  target->use(0, *target);

  character->unequip(0);
  target->unequip(0);
  character->use(0, *target);
  target->use(0, *target);

  character->equip(iceClone);
  target->equip(cureClone);
  character->use(0, *target);
  target->use(0, *target);

  delete ice;
  delete cure;
  delete character;
  delete target;
}

static void materiaSourceTests(void) {
  AMateria *ice;
  AMateria *cure;
  IMateriaSource *src;

  src = new MateriaSource;
  src->learnMateria(new Ice);
  src->learnMateria(new Cure);
  ice = src->createMateria("ice");
  cure = src->createMateria("cure");

  delete src;
  delete ice;
  delete cure;
}

int main(void) {
  TEST(subjectTests);
  TEST(iceMateriaTests);
  TEST(cureMateriaTests);
  TEST(characterTests);
  TEST(materiaSourceTests);
  return (0);
}
