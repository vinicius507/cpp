/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:21:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 16:25:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @file MateriaSource.hpp
 * @brief Declaration for the MateriaSource class.
 */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

/**
 * @class MateriaSource
 * @brief Represents a materia source.
 */
class MateriaSource : public IMateriaSource {
public:
  /**
   * @brief Default constructor for the MateriaSource.
   *
   * Constructs a MateriaSource object without base materias.
   */
  MateriaSource(void);

  /**
   * @brief Copy constructor for the MateriaSource class.
   *
   * Constructs a MateriaSource object by deep copying the contents from another
   * MateriaSource object.
   *
   * @param other The MateriaSource object to be copied.
   */
  MateriaSource(const MateriaSource &other);

  /**
   * @brief Destructor for the MateriaSource class.
   *
   * It deletes all learnt AMateria derived objects.
   */
  ~MateriaSource(void);

  /**
   * @brief Assignment operator for the MateriaSource class.
   *
   * @param other A reference to the MateriaSource object to be assigned.
   * @return A reference to the MateriaSource object.
   */
  MateriaSource &operator=(const MateriaSource &other);

  /**
   * @brief Retrieves a base materia learnt by the MateriaSource object.
   *
   * @param idx The index of the base materia object.
   * @return A pointer to the base materia object, if found, otherwise NULL.
   */
  AMateria *getBaseMateria(int idx) const;

  /**
   * @brief Learns how to create the AMateria derived object.
   *
   * It clones the AMateria and stores it into memory, as to use it to create
   * another AMateria derived objects.
   *
   * @param m A pointer to the AMateria derived object to be learnt by the
   * MateriaSource object.
   */
  void learnMateria(AMateria *m);

  /**
   * @brief Creates an AMateria derived object with the specified type.
   *
   * @param type The type of the AMateria derived object.
   * @return A pointer to the created AMateria derived object, if successful,
   * otherwise NULL.
   */
  AMateria *createMateria(const std::string &type);

private:
  static const int MAX_BASE_MATERIAS =
      4; /*<< The maximum number of base materias. */
  AMateria *
      baseMaterias[MAX_BASE_MATERIAS]; /*<< The MateriaSource knowledge base. */
};

#endif // !MATERIASOURCE_HPP
