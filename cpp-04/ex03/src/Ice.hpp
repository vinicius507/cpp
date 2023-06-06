/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:31:13 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 15:34:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice(void);

  Ice(const Ice &other);

  ~Ice(void);

  Ice &operator=(const Ice &other);

  AMateria *clone(void) const;

  void use(ICharacter &target);
};

#endif // !ICE_HPP
