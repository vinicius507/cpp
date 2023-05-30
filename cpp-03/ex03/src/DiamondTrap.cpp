/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:04:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/30 16:46:25 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
    : ClapTrap("D14M0ND-TP_clap_name"), ScavTrap("D14M0ND-TP_clap_name"),
      FragTrap("D14M0ND-TP_clap_name"), name("D14M0ND-TP") {
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"),
      FragTrap(name + "_clap_name"), name(name) {
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(), FragTrap() {
  *this = other;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "Administrator: even diamond break in the end, huh."
            << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  this->setName(other.getName());
  this->setHitPoints(other.getHitPoints());
  this->setEnergyPoints(other.getEnergyPoints());
  this->setAttackDamage(other.getAttackDamage());
  return (*this);
}

void DiamondTrap::attack(const std::string &target) {
  this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
  std::cout << this->getName()
            << ": Manufacturer code: " << this->ClapTrap::getName() << "."
            << std::endl;
}

std::string DiamondTrap::getName(void) const { return (this->name); }
