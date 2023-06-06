/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:49:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 16:14:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character(void);

  Character(const std::string &name);

  Character(const Character &other);

  ~Character(void);

  Character &operator=(const Character &other);

  const std::string &getName(void) const;

  AMateria *getMateria(int idx) const;

  void equip(AMateria *m);

  void unequip(int idx);

  void use(int idx, ICharacter &target);

private:
  std::string name;
  static const int INVENTORY_SIZE = 4;
  AMateria *inventory[INVENTORY_SIZE];
};

#endif // !CHARACTER_HPP
