/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:18:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 19:22:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIES_HPP
#define ZOMBIES_HPP

#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif // !ZOMBIES_HPP
