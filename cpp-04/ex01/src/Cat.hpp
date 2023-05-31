/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:37:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 15:03:15 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
  /**
   * @brief Default constructor for the Cat class.
   *
   * Constructs an Cat object without a type.
   */
  Cat(void);

  /**
   * @brief Copy constructor for the Cat class.
   *
   * Creates an Cat object by copying the contents of another Cat object.
   *
   * @param other The Cat object to be copied.
   */
  Cat(const Cat &other);

  /**
   * @brief Destructor for the Cat class.
   */
  ~Cat(void);

  /**
   * @brief Assignment operator for the Cat class.
   *
   * @param other The Cat object to be assigned.
   * @return A reference to the Cat object.
   */
  Cat &operator=(const Cat &other);

  /**
   * @brief Retrieves the Brain object of the Cat object.
   *
   * @return A pointer to the Brain object if it exists, otherwise NULL.
   */
  Brain *getBrain(void) const;

  /**
   * @brief The Cat meows.
   */
  void makeSound(void) const;

private:
  Brain *brain;
};

#endif // !CAT_HPP
