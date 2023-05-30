/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:08:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/30 15:30:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap("5C4V-TP") {
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(20);

  std::cout << this->getName() << ": Who goes there?!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(20);

  std::cout << this->getName() << ": Who goes there?!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.getName()) {
  this->setHitPoints(other.getHitPoints());
  this->setEnergyPoints(other.getEnergyPoints());
  this->setAttackDamage(other.getAttackDamage());

  std::cout << this->getName()
            << ": Who goes there?! What?! Another scavanger?!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "Administrator: Goodbye, " << this->getName()
            << ". (Gosh, I hate Scavs)." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  this->setName(other.getName());
  this->setHitPoints(other.getHitPoints());
  this->setEnergyPoints(other.getEnergyPoints());
  this->setAttackDamage(other.getAttackDamage());
  return (*this);
}

void ScavTrap::attack(std::string target) {
  if (this->isDead()) {
    std::cout << "Administrator: the ScavTrap can't attack because it is dead."
              << std::endl;
    return;
  }

  if (!this->hasEnergy()) {
    std::cout << this->getName() << ": *tries to attack but it has no energy *"
              << std::endl;
    return;
  }

  std::cout << this->getName() << ": take this!" << std::endl
            << this->getName() << ": *attacks " << target << "*" << std::endl;
  this->consumeEnergy();
}

void ScavTrap::guardGate(void) {
  if (this->isDead()) {
    std::cout << "Administrator: the ScavTrap can't enter gate keeper mode "
                 "because it is dead."
              << std::endl;
    return;
  }

  std::cout << this->getName() << ": ENTERING GATE KEEPER MODE." << std::endl;
}
