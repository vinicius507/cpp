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

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource(void);

  MateriaSource(const MateriaSource &other);

  ~MateriaSource(void);

  MateriaSource &operator=(const MateriaSource &other);

  AMateria *getBaseMateria(int idx) const;

  void learnMateria(AMateria *m);

  AMateria *createMateria(const std::string &type);

private:
  static const int MAX_BASE_MATERIAS = 4;
  AMateria *baseMaterias[MAX_BASE_MATERIAS];
};

#endif // !MATERIASOURCE_HPP
