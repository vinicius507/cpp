/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:16:50 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 19:16:24 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombies.hpp"

Zombie *newZombie(std::string name) { return new Zombie(name); }
