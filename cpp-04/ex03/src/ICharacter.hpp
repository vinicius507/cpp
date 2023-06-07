/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:55:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 16:58:33 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ICharacter.hpp
 * @brief Declaration for the ICharacter class.
 */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

/**
 * @class ICharacter
 * @brief Represents an interface of a Character.
 */
class ICharacter {
public:
  /**
   * @brief Destructor for the ICharacter class.
   */
  virtual ~ICharacter(){};

  /**
   * @brief Retrieves the name of the ICharacter object.
   */
  virtual const std::string &getName(void) const = 0;

  /**
   * @brief Equips an AMateria derived object.
   *
   * Should the inventory be full, the AMateria object will not be equiped.
   *
   * @param m The AMateria derived object to be equiped.
   */
  virtual void equip(AMateria *m) = 0;

  /**
   * @brief Unequips an AMateria derived object.
   *
   * Removes the AMateria derived object from the inventory.
   *
   * @param idx The index of the AMateria object on the inventory.
   */
  virtual void unequip(int idx) = 0;

  /**
   * @brief Uses an AMateria derived object from the inventory at the specified
   * target.
   *
   * @param idx The index of the AMateria derived object on the inventory.
   * @param target The target to use the AMateria derived object against.
   */
  virtual void use(int idx, ICharacter &target) = 0;
};

#endif // !ICHARACTER_HPP
