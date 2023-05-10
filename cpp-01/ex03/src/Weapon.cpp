/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:58:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 21:00:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("") {}

Weapon::~Weapon(void) {}

Weapon::Weapon(const Weapon &other) : type(other.type) {}

std::string Weapon::getType(void) { return (this->type); }

void Weapon::setType(std::string type) { this->type = type; }
