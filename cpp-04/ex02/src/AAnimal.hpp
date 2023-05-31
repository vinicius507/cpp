/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:27:14 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 15:46:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
public:
  /**
   * @brief Default constructor for the AAnimal class.
   *
   * Constructs an AAnimal object without a type.
   */
  AAnimal(void);

  /**
   * @brief Parametrized constructor for the AAnimal class.
   *
   * Constructs an AAnimal object with the specified type.
   */
  AAnimal(const std::string _type);

  /**
   * @brief Copy constructor for the AAnimal class.
   *
   * Creates an AAnimal object by copying the contents of another AAnimal
   * object.
   *
   * @param other The AAnimal object to be copied.
   */
  AAnimal(const AAnimal &other);

  /**
   * @brief Virtual destructor for the AAnimal class.
   */
  virtual ~AAnimal(void);

  /**
   * @brief Assignment operator for the AAnimal class.
   *
   * @param other The AAnimal object to be assigned.
   * @return A reference to the AAnimal object.
   */
  AAnimal &operator=(const AAnimal &other);

  /**
   * @brief Retrieves the type of the AAnimal object.
   */
  std::string getType(void) const;

  /**
   * @brief Abstract method for the AAnimal class.
   *
   * The derived object makes an unique sound.
   */
  virtual void makeSound(void) const = 0;

protected:
  std::string type; /**< The type of the animal. */
};

#endif // !ANIMAL_HPP
