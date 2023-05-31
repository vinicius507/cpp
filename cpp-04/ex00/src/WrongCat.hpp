/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:25:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:27:04 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  /**
   * @brief Default constructor for the WrongCat class.
   *
   * Constructs an WrongCat object without a type.
   */
  WrongCat(void);

  /**
   * @brief Copy constructor for the WrongCat class.
   *
   * Creates an WrongCat object by copying the contents of another WrongCat
   * object.
   *
   * @param other The WrongCat object to be copied.
   */
  WrongCat(const WrongCat &other);

  /**
   * @brief Destructor for the WrongCat class.
   */
  ~WrongCat(void);

  /**
   * @brief Assignment operator for the WrongCat class.
   *
   * @param other The WrongCat object to be assigned.
   * @return A reference to the WrongCat object.
   */
  WrongCat &operator=(const WrongCat &other);

  /**
   * @brief The WrongCat meows.
   */
  void makeSound(void) const;
};

#endif // !CAT_HPP
