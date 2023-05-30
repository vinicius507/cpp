/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:02:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/30 16:18:04 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
  DiamondTrap diamond;

  diamond.whoAmI();
  diamond.attack("user");
  diamond.guardGate();
  diamond.highFivesGuys();
  diamond.ScavTrap::setEnergyPoints(0);
  diamond.attack("user");
  return (0);
}
