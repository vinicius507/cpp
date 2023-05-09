/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horde.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:31:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 19:39:35 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORDE_HPP
#define HORDE_HPP

#include "Zombie.hpp"
#include <iostream>

/**
 * @brief Creates a horde of named Zombies.
 *
 * @param n The number of zombies.
 * @param name The name of the zombies.
 * @return The horde Zombies.
 */
Zombie *zombieHorde(int n, std::string name);

#endif // !HORDE_HPP
