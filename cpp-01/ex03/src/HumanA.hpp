/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:01:39 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/11 13:49:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file HumanA.hpp
 * @brief Declaration of the HumanA class.
 */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

/**
 * @class HumanA
 * @brief Represents a Human with a name and a weapon.
 */
class HumanA {
public:
  /**
   * @brief Default constructor for the HumanA class.
   *
   * @param name The name of the HumanA.
   * @param weapon The weapon of the HumanA.
   */
  HumanA(std::string name, Weapon &weapon);

  /**
   * @brief Default destructor for the HumanA class.
   */
  ~HumanA(void);

  /**
   * @brief The human attacks with its weapon.
   */
  void attack(void);

private:
  std::string name; /**< The name of the human. */
  Weapon &weapon;   /**< The weapon of the human. */
};

#endif
