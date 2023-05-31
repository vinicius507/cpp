/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:09:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:09:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
  /**
   * @brief Default constructor for the Dog class.
   *
   * Constructs an Dog object without a type.
   */
  Dog(void);

  /**
   * @brief Copy constructor for the Dog class.
   *
   * Creates an Dog object by copying the contents of another Dog object.
   *
   * @param other The Dog object to be copied.
   */
  Dog(const Dog &other);

  /**
   * @brief Destructor for the Dog class.
   */
  ~Dog(void);

  /**
   * @brief Assignment operator for the Dog class.
   *
   * @param other The Dog object to be assigned.
   * @return A reference to the Dog object.
   */
  Dog &operator=(const Dog &other);

  /**
   * @brief The Dog barks.
   */
  void makeSound(void) const;
};

#endif // !CAT_HPP
