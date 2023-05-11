/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:52:17 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/11 14:02:18 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file HumanB.hpp
 * @brief Declaration of the HumanB class.
 */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

/**
 * @class HumanB
 * @brief Represents a Human with a name and _maybe_ a weapon.
 */
class HumanB {
public:
  /**
   * @brief Constructor for the HumanB class.
   *
   * @param name The name of the HumanB.
   */
  HumanB(std::string name);

  /**
   * @brief Default destructor for the HumanB class.
   */
  ~HumanB(void);

  /**
   * @brief Sets the HumanB weapon.
   *
   * @param weapon The new weapon for the HumanB.
   */
  void setWeapon(Weapon &weapon);

  /**
   * @brief The human attacks with a weapon, if he has one. Otherwise, he
   * attacks with his fists.
   */
  void attack(void);

private:
  std::string name; /**< The name of the HumanB. */
  Weapon *weapon;   /**< The weapon of the HumanB. */
};

#endif
