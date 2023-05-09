/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:52:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 19:51:58 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombies.hpp"

int main(void) {
  Zombie *marvin;

  randomChump("Vini");
  marvin = newZombie("marvin");
  marvin->announce();
  delete marvin;
  return (0);
}
