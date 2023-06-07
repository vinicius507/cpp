/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 16:42:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file AMateria.hpp
 * @brief Declaration for the base class AMateria.
 */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

/**
 * @class AMateria
 * @brief Represents a materia.
 */
class AMateria {
public:
  /**
   * @brief Default constructor for the AMateria class.
   *
   * Constructs an AMateria object with no type.
   */
  AMateria(void);

  /**
   * @brief Parametrized constructor for the AMateria class.
   *
   * Constructs an AMateria object with the specified type.
   *
   * @param type The type of the AMateria object.
   */
  explicit AMateria(const std::string &type);

  /**
   * @brief Copy constructor for the AMateria class.
   *
   * Constructs an AMateria object by copying the contents from another AMateria
   * object.
   *
   * @param other The AMateria object to be copied.
   */
  AMateria(const AMateria &other);

  /**
   * @brief Virtual destructor for the AMateria class.
   */
  virtual ~AMateria(void);

  /**
   * @brief Assignment operator for the AMateria class.
   *
   * @param other A reference to the AMateria object to be assigned.
   * @return A reference to the AMateria object.
   */
  AMateria &operator=(const AMateria &other);

  /**
   * @brief Retrieves the type of the AMateria object.
   */
  const std::string &getType(void) const;

  /**
   * @brief Clones the AMateria object.
   *
   * @return A pointer to the cloned AMateria.
   */
  virtual AMateria *clone(void) const = 0;

  /**
   * @brief Uses the AMateria object against a target.
   *
   * @param target The target to use the AMateria against.
   */
  virtual void use(ICharacter &target);

protected:
  const std::string type; /**< The type of the AMateria object. */
};

#endif // !AMATERIA_HPP
