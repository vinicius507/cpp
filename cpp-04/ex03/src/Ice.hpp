/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:31:13 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 16:46:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Ice.hpp
 * @brief Declaration for the Ice class.
 */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

/**
 * @class Ice
 * @brief Represents an Ice materia.
 */
class Ice : public AMateria {
public:
  /**
   * @brief Default constructor for the Ice class.
   *
   * Constructs an Ice object with the "ice" type.
   */
  Ice(void);

  /**
   * @brief Copy constructor for the Ice class.
   *
   * Constructs an Ice object by copying the contents from another Ice object.
   *
   * @param other The Ice object to be copied.
   */
  Ice(const Ice &other);

  /**
   * @brief Destructor for the Ice class.
   */
  ~Ice(void);

  /**
   * @brief Assignment operator for the Ice class.
   *
   * @param other A reference to the Ice object to be assigned.
   * @return A reference to the Ice object.
   */
  Ice &operator=(const Ice &other);

  /**
   * @brief Clones the Ice object.
   *
   * @return A pointer to the cloned Ice object.
   */
  AMateria *clone(void) const;

  /**
   * @brief Shoots an ice bolt at the target.
   *
   * @param target The target of the ice bolt.
   */
  void use(ICharacter &target);
};

#endif // !ICE_HPP
