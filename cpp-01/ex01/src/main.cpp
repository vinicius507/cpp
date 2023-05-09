/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:30:53 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 19:42:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horde.hpp"
#include <string>

int main(void) {
  Zombie *horde;

  for (int n = 0; n < 10; n++) {
    horde = zombieHorde(n, "horde-" + std::to_string(n));
    for (int i = 0; i < n; i++) {
      horde[i].announce();
    }
    delete[] horde;
  }
}
