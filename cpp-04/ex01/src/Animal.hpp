/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:27:14 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:30:21 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
  /**
   * @brief Default constructor for the Animal class.
   *
   * Constructs an Animal object without a type.
   */
  Animal(void);

  /**
   * @brief Parametrized constructor for the Animal class.
   *
   * Constructs an Animal object with the specified type.
   */
  Animal(const std::string _type);

  /**
   * @brief Copy constructor for the Animal class.
   *
   * Creates an Animal object by copying the contents of another Animal object.
   *
   * @param other The Animal object to be copied.
   */
  Animal(const Animal &other);

  /**
   * @brief Virtual destructor for the Animal class.
   */
  virtual ~Animal(void);

  /**
   * @brief Assignment operator for the Animal class.
   *
   * @param other The Animal object to be assigned.
   * @return A reference to the Animal object.
   */
  Animal &operator=(const Animal &other);

  /**
   * @brief Retrieves the type of the Animal object.
   */
  std::string getType(void) const;

  /**
   * @brief The Animal object makes an unique sound.
   */
  virtual void makeSound(void) const;

protected:
  std::string type; /**< The type of the animal. */
};

#endif // !ANIMAL_HPP
