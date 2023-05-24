/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:56:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 14:01:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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

private:
  int rawBits; /**< The raw integer value representing the fixed-point number.
                */
  static const int fractionalBits = 8; /**< The position of the binary point
                         within the fixed-point number, indicating the number of
                         fractional bits. */
};

#endif // !FIXED_HPP
