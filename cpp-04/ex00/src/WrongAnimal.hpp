/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:15:05 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:29:27 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
public:
  /**
   * @brief Default constructor for the WrongAnimal class.
   *
   * Constructs an WrongAnimal object without a type.
   */
  WrongAnimal(void);

  /**
   * @brief Parametrized constructor for the WrongAnimal class.
   *
   * Constructs an WrongAnimal object with the specified type.
   */
  WrongAnimal(const std::string _type);

  /**
   * @brief Copy constructor for the WrongAnimal class.
   *
   * Creates an WrongAnimal object by copying the contents of another
   * WrongAnimal object.
   *
   * @param other The WrongAnimal object to be copied.
   */
  WrongAnimal(const WrongAnimal &other);

  /**
   * @brief Destructor for the WrongAnimal class.
   */
  ~WrongAnimal(void);

  /**
   * @brief Assignment operator for the WrongAnimal class.
   *
   * @param other The WrongAnimal object to be assigned.
   * @return A reference to the WrongAnimal object.
   */
  WrongAnimal &operator=(const WrongAnimal &other);

  /**
   * @brief Retrieves the type of the WrongAnimal object.
   */
  std::string getType(void) const;

  /**
   * @brief The WrongAnimal object makes an unique sound.
   */
  void makeSound(void) const;

protected:
  std::string type; /**< The type of the animal. */
};

#endif // !WRONGANIMAL_HPP
