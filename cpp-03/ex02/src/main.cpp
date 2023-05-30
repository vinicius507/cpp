/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:02:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/30 15:46:52 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

static void randomRepair(ClapTrap &clap) {
  clap.beRepaired((clap.getHitPoints() * (clap.getEnergyPoints() / 8) / 2) % 4);
}

/**
 * @brief A ClapTrap object challengs another one to battle.
 *
 * @param challenger The ClapTrap that started the battle.
 * @param defender The ClapTrap that will defend.
 * @return `true` if the challenger won the battle, `false` otherwise.
 */
static bool challenge(ClapTrap &challenger, ClapTrap &defender) {
  std::cout << "[BATTLE]" << std::endl;
  bool successfullAttack;

  do {
    successfullAttack = challenger.hasEnergy();
    challenger.attack(defender.getName());
    if (successfullAttack) {
      defender.takeDamage(challenger.getAttackDamage());
    }
    randomRepair(defender);

    if (defender.isDead()) {
      break;
    }

    successfullAttack = defender.hasEnergy();
    defender.attack(challenger.getName());
    if (successfullAttack) {
      challenger.takeDamage(defender.getAttackDamage());
    }
    randomRepair(challenger);
  } while (!challenger.isDead() && !defender.isDead());

  return (!challenger.isDead());
}

int main(void) {
  ClapTrap clap;
  ScavTrap scav;
  FragTrap frag;
  ClapTrap *winner;

  frag.highFivesGuys();
  clap.setAttackDamage(33);
  scav.guardGate();
  if (challenge(clap, scav)) {
    winner = &clap;
  } else {
    winner = &scav;
  };
  if (!challenge(*winner, frag)) {
    winner = &frag;
  }
  std::cout << winner->getName() << " wins the tournament!" << std::endl;
  return (0);
}
