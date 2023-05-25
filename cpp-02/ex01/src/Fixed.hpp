/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:52:24 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 14:31:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

/**
 * @class Fixed
 * @brief Represents a Fixed Point Number.
 *
 * Fixed-point numbers are useful in situations where floating-point arithmetic
 * is not desired due to performance or precision constraints. They can be used
 * to handle decimal values without the overhead of floating-point operations,
 * making them particularly useful in embedded systems, financial calculations,
 * and other domains that require high precision.
 */
class Fixed {
public:
  /**
   * @brief Default constructor for the Fixed class.
   *
   * Constructs a Fixed object with a default value of zero.
   */
  Fixed(void);

  /**
   * @brief Constructor for the Fixed class.
   *
   * Constructs a Fixed object from a integer value.
   *
   * @param n The integer value to be converted to the Fixed representation.
   */
  explicit Fixed(const int n);

  /**
   * @brief Constructor for the Fixed class.
   *
   * Constructs a Fixed object with the
   *
   * @param f The floating-point value to be converted to the Fixed
   * representation.
   */
  explicit Fixed(const float f);

  /**
   * @brief Copy constructor for the Fixed class.
   *
   * Constructs a new Fixed object by copying the contents of another Fixed
   * object.
   *
   * @param other The Fixed object to be copied.
   */
  Fixed(const Fixed &other);

  /**
   * @brief Destructor for the Fixed class.
   */
  ~Fixed(void);

  /**
   * @brief Assignment operator for the Fixed class.
   *
   * Assigns the value of another Fixed object to this Fixed object.
   *
   * @param other The Fixed object to be assigned.
   * @return A reference to the assigned Fixed object.
   */
  Fixed &operator=(const Fixed &other);

  /**
   * @brief Retrieves the raw integer value representing the fixed-point number.
   *
   * @return The raw integer value of the fixed-point number.
   */
  int getRawBits(void) const;

  /**
   * @brief Sets the raw integer value representing the fixed-point number.
   *
   * @param rawBits The raw integer value to set for the fixed-point number.
   */
  void setRawBits(const int rawBits);

  /**
   * @brief Converts the fixed-point number to an integer.
   *
   * @return The converted integer.
   */
  int toInt(void) const;

  /**
   * @brief Converts the fixed-point number to a floating-point number.
   *
   * @return The converted floating-point number.
   */
  float toFloat(void) const;

private:
  int rawBits; /**< The raw integer value representing the fixed-point number.
                */
  static const int fractionalBits = 8; /**< The position of the binary point
                         within the fixed-point number, indicating the number of
                         fractional bits. */
};

/**
 * @brief Overload for the insertion operator for the Fixed class.
 *
 * It insterts the fixed-point number into the output stream in a
 * floating-point format.
 *
 * @param out The output stream.
 */
std::ostream &operator<<(std::ostream &out, Fixed const &f);

#endif // !FIXED_HPP
