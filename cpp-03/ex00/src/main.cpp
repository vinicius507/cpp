/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:02:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 23:53:15 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
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
  ClapTrap jarvis("jarvis");
  ClapTrap jarvisWeakClone(jarvis);
  ClapTrap *victoriousClapTrap;

  clap.setAttackDamage(3);
  jarvis.setAttackDamage(4);
  jarvisWeakClone.setAttackDamage(1);

  if (challenge(clap, jarvis)) {
    victoriousClapTrap = &clap;
  } else {
    victoriousClapTrap = &jarvis;
  }
  if (challenge(*victoriousClapTrap, jarvisWeakClone)) {
    victoriousClapTrap->attack(jarvisWeakClone.getName());
    jarvisWeakClone.takeDamage(victoriousClapTrap->getAttackDamage());
  } else {
    victoriousClapTrap = &jarvisWeakClone;
    victoriousClapTrap->attack(jarvis.getName());
    jarvis.takeDamage(victoriousClapTrap->getAttackDamage());
  }
  return 0;
}
