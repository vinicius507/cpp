/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:43:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 16:49:12 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Cure.hpp
 * @brief Declaration for the Cure class.
 */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

/**
 * @class Cure
 * @brief Represents a Cure materia.
 */
class Cure : public AMateria {
public:
  /**
   * @brief Default constructor for the Cure class.
   *
   * Constructs a Cure object with the "cure" type.
   */
  Cure(void);

  /**
   * @brief Copy constructor for the Cure class.
   *
   * Constructs a Cure object by copying the contents from another Cure object.
   *
   * @param other The Cure object to be copied.
   */
  Cure(const Cure &other);

  /**
   * @brief Destructor for the Cure class.
   */
  ~Cure(void);

  /**
   * @brief Assignment operator for the Cure class.
   *
   * @param other A reference to the Cure object to be assigned.
   * @return A reference to the Cure object.
   */
  Cure &operator=(const Cure &other);

  /**
   * @brief Clones the Cure materia.
   *
   * @return The cloned Cure materia.
   */
  AMateria *clone(void) const;

  /**
   * @brief Heals a target.
   *
   * @param target The target to be healed.
   */
  void use(ICharacter &target);
};

#endif // !CURE_HPP
