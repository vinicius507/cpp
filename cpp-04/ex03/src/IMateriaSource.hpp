/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:19:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 16:21:39 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file IMateriaSource.hpp
 * @brief Declaration for the IMateriaSource class.
 */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

/**
 * @class IMateriaSource
 * @brief Represents an interface of a MateriaSource.
 */
class IMateriaSource {
public:
  /**
   * @brief Destructor for the IMateriaSource class.
   */
  virtual ~IMateriaSource(void){};

  /**
   * @brief The IMateriaSource object learns how to create the AMateria derived
   * object.
   *
   * @param m The AMateria object to be learnt by the IMateriaSource object.
   */
  virtual void learnMateria(AMateria *m) = 0;

  /**
   * @brief Creates an AMateria derived object with the specified type.
   *
   * If the IMateriaSource object did not learn to create the AMateria derived
   * object before, it does nothing.
   *
   * @param type The type of the AMateria derived object to be created.
   * @return A pointer to the AMateria object created, if successful, otherwise
   * NULL.
   */
  virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif // !IMATERIASOURCE_HPP
