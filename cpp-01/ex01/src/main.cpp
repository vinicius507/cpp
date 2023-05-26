/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:30:53 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/26 14:48:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horde.hpp"
#include <sstream>
#include <string>

int main(void) {
  Zombie *horde;
  std::stringstream ss;

  for (int n = 0; n < 10; n++) {
    ss << n;
    horde = zombieHorde(n, "horde-" + ss.str());
    for (int i = 0; i < n; i++) {
      horde[i].announce();
    }
    ss.str(std::string());
    delete[] horde;
  }
}
