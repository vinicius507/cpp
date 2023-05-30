/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:34:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/30 15:48:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap("FR4G-TP") {
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);

  std::cout << this->getName() << ": Give me them frags!" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);

  std::cout << this->getName() << ": Give me them frags!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
  *this = other;
  std::cout << this->getName() << ": You got some frags, huh!" << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "Administrator: this Frag was a crazy one..." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  this->setName(other.getName());
  this->setHitPoints(other.getHitPoints());
  this->setEnergyPoints(other.getEnergyPoints());
  this->setAttackDamage(other.getAttackDamage());
  return (*this);
}

void FragTrap::highFivesGuys(void) {
  std::cout << this->getName()
            << ": Let's go! It's gonna be legendary! High five!" << std::endl;
}
