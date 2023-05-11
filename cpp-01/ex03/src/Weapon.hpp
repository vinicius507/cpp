/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:49:57 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 20:55:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Weapon.hpp
 * @brief Declaration of the Weapon class.
 */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

/**
 * @class Weapon
 * @brief Represents a weapon with a type.
 */
class Weapon {
public:
  /**
   * @brief Default constructor for the Weapon class.
   */
  Weapon(void);

  /**
   * @brief Copy constructor for the Weapon class.
   *
   * @param other The other instance of a Weapon.
   */
  Weapon(const Weapon &other);

  /**
   * @brief Default destructor for the Weapon class.
   */
  ~Weapon(void);

  /**
   * @brief Getter for the type of the weapon.
   */
  const std::string &getType(void) const;

  /**
   * @brief Setter for the type of the weapon.
   *
   * @param type The type of the weapon.
   */
  void setType(std::string type);

private:
  std::string type; /**< The type of the weapon. */
};

#endif // !WEAPON_HPP
