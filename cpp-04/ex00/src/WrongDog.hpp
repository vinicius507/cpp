/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:33:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:34:04 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
public:
  /**
   * @brief Default constructor for the WrongDog class.
   *
   * Constructs an WrongDog object without a type.
   */
  WrongDog(void);

  /**
   * @brief Copy constructor for the WrongDog class.
   *
   * Creates an WrongDog object by copying the contents of another WrongDog
   * object.
   *
   * @param other The WrongDog object to be copied.
   */
  WrongDog(const WrongDog &other);

  /**
   * @brief Destructor for the WrongDog class.
   */
  ~WrongDog(void);

  /**
   * @brief Assignment operator for the WrongDog class.
   *
   * @param other The WrongDog object to be assigned.
   * @return A reference to the WrongDog object.
   */
  WrongDog &operator=(const WrongDog &other);

  /**
   * @brief The WrongDog barks.
   */
  void makeSound(void) const;
};

#endif // !CAT_HPP
