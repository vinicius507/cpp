/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:55:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 15:29:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter {
public:
  virtual ~ICharacter();

  virtual const std::string &getName(void) const = 0;

  virtual void equip(AMateria *m) = 0;

  virtual void unequip(int idx) = 0;

  virtual void use(int idx, ICharacter &target);
};

#endif // !ICHARACTER_HPP
