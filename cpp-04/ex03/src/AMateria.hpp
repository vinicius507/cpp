/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:52:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 15:30:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
public:
  AMateria(void);

  explicit AMateria(const std::string &type);

  AMateria(const AMateria &other);

  virtual ~AMateria(void);

  AMateria &operator=(const AMateria &other);

  const std::string &getType(void) const;

  virtual AMateria *clone(void) const = 0;

  virtual void use(ICharacter &target);

protected:
  const std::string type;
};

#endif // !AMATERIA_HPP
