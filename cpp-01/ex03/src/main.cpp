/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:49:24 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 21:00:21 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int main(void) {
  Weapon greatsword;

  greatsword.setType("sword");
  std::cout << greatsword.getType() << std::endl;
  return (0);
}
