/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:30:24 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/20 12:53:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Serializer.hpp
 * @brief Declaration for the Serializer class.
 */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

/**
 * @class Serializer
 * @brief Static class for serialization and deserialization of `Data *`
 * objects.
 *
 * It serializes a pointer to a Data object by using reinterpret_cast with a
 * target type of uintptr_t. The deserialization works the same way, but the
 * target type is `Data *`.
 */
class Serializer {
public:
  /**
   * @brief Serializes a pointer to a Data object into an `uintptr_t`.
   *
   * @param ptr A pointer to a Data object.
   * @return The serialized uintptr_t value.
   */
  static uintptr_t serialize(Data *ptr);

  /**
   * @brief Deserializes an `uintptr_t` value to a pointer to a Data object.
   *
   * @param raw A serialized uintptr_t value.
   * @return A pointer to the Data object.
   */
  static Data *deserialize(uintptr_t raw);

private:
  /**
   * @brief Constructor for the Serializer class.
   */
  Serializer(void);

  /**
   * @brief Copy constructor for the Serializer class.
   *
   * @param other The Serializer object to be copied.
   */
  Serializer(const Serializer &other);

  /**
   * @brief Destructor for the Serializer class.
   */
  ~Serializer(void);

  /**
   * @brief Assignment operator for the Serializer class.
   *
   * @param other The Serializer object to be assigned.
   * @return A reference to the Serializer object.
   */
  Serializer &operator=(const Serializer &other);
};

#endif // !SERIALIZER_HPP
