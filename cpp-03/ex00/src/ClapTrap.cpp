/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:57:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 23:52:24 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

const unsigned int ClapTrap::MAX_HP = 10;

ClapTrap::ClapTrap(void)
    : name("CL4P-TP"), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << this->name << ": Hey, best friend!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(10) {
  std::cout << this->name << ": Hey, best friend!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  *this = other;
  std::cout << this->name << ": Hey, best friend! Wait, you're me, too!"
            << std::endl;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "Administrator: Goodbye, " << this->getName() << "."
            << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  const_cast<std::string &>(this->name) = other.name + " (clone)";
  this->setHitPoints(other.getHitPoints());
  this->energyPoints = other.energyPoints;
  this->setAttackDamage(other.getAttackDamage());
  std::cout << this->name << ": Hey, best friend! Wait, you're me!"
            << std::endl;
  return (*this);
}

void ClapTrap::attack(const std::string &target) {
  if (this->isDead()) {
    std::cout << "Administrator: the ClapTrap can't attack because it is dead."
              << std::endl;
    return;
  }
  if (!this->hasEnergy()) {
    std::cout << this->name << ": *tries to attack but it has no energy*"
              << std::endl;
    return;
  }
  std::cout << this->name << ": *attacks " << target << "*" << std::endl;
  this->consumeEnergy();
}

void ClapTrap::takeDamage(unsigned int amount) {
  unsigned int hp;

  if (this->isDead()) {
    std::cout << "Administrator: Stop, stop! He's already dead!" << std::endl;
    return;
  }
  hp = this->getHitPoints();
  if (amount >= hp) {
    hp = 0;
    std::cout << this->name << ": *dies*" << std::endl;
  } else {
    hp -= amount;
    std::cout << this->name << ": *takes " << amount << " damage*" << std::endl;
  }
  this->setHitPoints(hp);
}

void ClapTrap::beRepaired(unsigned int amount) {
  unsigned int hp;

  if (this->isDead()) {
    std::cout
        << "Administrator: the ClapTrap can't repair itself because it is dead."
        << std::endl;
    return;
  }

  if (!this->hasEnergy()) {
    std::cout << this->getName()
              << ": *tries to repair itself but it has no energy*" << std::endl;
    return;
  }

  hp = this->getHitPoints() + amount;
  this->setHitPoints(hp);
  std::cout << this->getName() << ": *repairs itself to "
            << this->getHitPoints() << " hit points*" << std::endl;
  this->consumeEnergy();
}

std::string ClapTrap::getName() const { return (this->name); }

unsigned int ClapTrap::getHitPoints() const { return (this->hitPoints); }

unsigned int ClapTrap::getEnergyPoints() const { return (this->energyPoints); }

unsigned int ClapTrap::getAttackDamage() const { return (this->attackDamage); }

void ClapTrap::setHitPoints(unsigned int hitPoints) {
  if (hitPoints > MAX_HP) {
    this->hitPoints = MAX_HP;
    return;
  }
  this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
  this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
  this->attackDamage = attackDamage;
}

bool ClapTrap::hasEnergy() const { return (this->energyPoints > 0); }

void ClapTrap::consumeEnergy(void) { this->energyPoints--; }

bool ClapTrap::isDead(void) const { return (this->hitPoints == 0); };
