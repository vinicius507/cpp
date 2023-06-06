/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:43:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 15:43:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure(void);

  Cure(const Cure &other);

  ~Cure(void);

  Cure &operator=(const Cure &other);

  AMateria *clone(void) const;

  void use(ICharacter &target);
};

#endif // !CURE_HPP
