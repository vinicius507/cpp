/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:49:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 16:56:25 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Character.hpp
 * @brief Declaration for the Character class.
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

/**
 * @class Character
 * @brief Represents a Character.
 */
class Character : public ICharacter {
public:
  /**
   * @brief Default constructor for the Character class.
   *
   * Constructs a Character with the default name "He-Who-Must-Not-Be-Named".
   */
  Character(void);

  /**
   * @brief Parametrized constructor for the Character class.
   *
   * Constructs a Character object with the specified name.
   *
   * @param name The name of the Character object.
   */
  Character(const std::string &name);

  /**
   * @brief Copy constructor for the Character class.
   *
   * Constructs a Character object by copying the contents from another
   * Character object.
   *
   * @param other The character object to be copied.
   */
  Character(const Character &other);

  /**
   * @brief Destructor for the Character class.
   */
  ~Character(void);

  /**
   * @brief Assignment operator for the Character class.
   *
   * @param other A reference to the Character object to be assigned.
   * @return A reference to the Character object.
   */
  Character &operator=(const Character &other);

  /**
   * @brief Retrieves the name of the Character object.
   */
  const std::string &getName(void) const;

  /**
   * @brief Retrieves an AMateria derived object from the inventory.
   *
   * @param idx The index of the materia on the inventory.
   * @return A pointer to the AMateria object, if found, otherwise NULL.
   */
  AMateria *getMateria(int idx) const;

  /**
   * @brief Equips an AMateria derived object.
   *
   * Should the inventory be full, the AMateria object will not be equiped.
   *
   * @param m The AMateria derived object to be equiped.
   */
  void equip(AMateria *m);

  /**
   * @brief Unequips an AMateria derived object.
   *
   * Removes the AMateria derived object from the inventory.
   *
   * @param idx The index of the AMateria object on the inventory.
   */
  void unequip(int idx);

  /**
   * @brief Uses an AMateria derived object from the inventory at the specified
   * target.
   *
   * @param idx The index of the AMateria derived object on the inventory.
   * @param target The target to use the AMateria derived object against.
   */
  void use(int idx, ICharacter &target);

private:
  std::string name; /**< The name of the Character object. */
  static const int INVENTORY_SIZE =
      4; /**< The size of the Character object inventory. */
  AMateria
      *inventory[INVENTORY_SIZE]; /**< The inventory of the Character object. */
};

#endif // !CHARACTER_HPP
