/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:52:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 16:22:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombies.hpp"

int main(void) {
  Zombie me = Zombie("Vini");
  Zombie *marvin = newZombie("Marvin");

  me.announce();
  marvin->announce();
  delete marvin;
  return (0);
}
