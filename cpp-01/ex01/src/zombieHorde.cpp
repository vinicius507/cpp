/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:31:55 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 19:43:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horde.hpp"

Zombie *zombieHorde(int n, std::string name) {
  Zombie *horde;

  horde = new Zombie[n];
  for (int i = 0; i < n; i++) {
    horde[i].setName(name);
  }
  return (horde);
}
