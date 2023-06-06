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

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
  virtual ~IMateriaSource(void){};

  virtual void learnMateria(AMateria *m) = 0;

  virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif // !IMATERIASOURCE_HPP
