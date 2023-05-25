/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:52:24 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 15:06:43 by vgoncalv         ###   ########.fr       */
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
   * @brief Greater-than comparison operator.
   *
   * Compares the value of the current Fixed object with another Fixed object
   * `other`.
   *
   * @param other The Fixed object to compare with.
   * @return A boolean indicating whether the current object is greater than
   * `other`.
   */
  bool operator>(const Fixed &other);

  /**
   * @brief Less-than comparison operator.
   *
   * Compares the value of the current Fixed object with another Fixed object
   * `other`.
   *
   * @param other The Fixed object to compare with.
   * @return A boolean indicating whether the current object is less than
   * `other`.
   */
  bool operator<(const Fixed &other);

  /**
   * @brief Less-than or equal to comparison operator.
   *
   * Compares the value of the current Fixed object with another Fixed object
   * `other`.
   *
   * @param other The Fixed object to compare with.
   * @return A boolean indicating whether the current object is less than or
   * equal to `other`.
   */
  bool operator>=(const Fixed &other);

  /**
   * @brief Greater-than or equal to comparison operator.
   *
   * Compares the value of the current Fixed object with another Fixed object
   * `other`.
   *
   * @param other The Fixed object to compare with.
   * @return A boolean indicating whether the current object is greater than or
   * equal to `other`.
   */
  bool operator<=(const Fixed &other);

  /**
   * @brief Equality comparison operator.
   *
   * Compares the value of the current Fixed object with another Fixed object
   * `other`.
   *
   * @param other The Fixed object to compare with.
   * @return A boolean indicating whether the two objects are equal.
   */
  bool operator==(const Fixed &other);

  /**
   * @brief Inequality comparison operator.
   *
   * Compares the value of the current Fixed object with another Fixed object
   * `other`.
   *
   * @param other The Fixed object to compare with.
   * @return A boolean indicating whether the two objects are not equal.
   */
  bool operator!=(const Fixed &other);

  /**
   * @brief Addition operator.
   *
   * Performs addition between the current Fixed object and `other`.
   *
   * @param other The Fixed object to add.
   * @return A new Fixed object representing the result of the addition.
   */
  Fixed operator+(const Fixed &other);

  /**
   * @brief Subtraction operator.
   *
   * Performs subtraction between the current Fixed object and `other`.
   *
   * @param other The Fixed object to subtract.
   * @return A new Fixed object representing the result of the subtraction.
   */
  Fixed operator-(const Fixed &other);

  /**
   * @brief Multiplication operator.
   *
   * Performs multiplication between the current Fixed object and `other`.
   *
   * @param other The Fixed object to multiply.
   * @return A new Fixed object representing the result of the multiplication.
   */
  Fixed operator*(const Fixed &other);

  /**
   * @brief Division operator.
   *
   * Performs division between the current Fixed object and `other`.
   *
   * @param other The Fixed object to divide by.
   * @return A new Fixed object representing the result of the division.
   */
  Fixed operator/(const Fixed &other);

  /**
   * @brief Pre-increment operator.
   *
   * Increments the value of the current Fixed object and returns a reference to
   * the updated object.
   *
   * @return A reference to the updated Fixed object after the increment.
   */
  Fixed &operator++(void);

  /**
   * @brief Pre-decrement operator.
   *
   * Decrements the value of the current Fixed object and returns a reference to
   * the updated object.
   *
   * @return A reference to the updated Fixed object after the decrement.
   */
  Fixed &operator--(void);

  /**
   * @brief Post-increment operator.
   *
   * Increments the value of the current Fixed object and returns a copy of the
   * original object before the increment.
   *
   * @return A copy of the original Fixed object before the increment.
   */
  Fixed operator++(int);

  /**
   * @brief Post-decrement operator.
   *
   * Decrements the value of the current Fixed object and returns a copy of the
   * original object before the decrement.
   *
   * @return A copy of the original Fixed object before the decrement.
   */
  Fixed operator--(int);

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

  /**
   * @brief Minimum function (non-const version).
   *
   * Returns a reference to the Fixed object with the minimum value between `a`
   * and `b`.
   *
   * @param a The first Fixed object.
   * @param b The second Fixed object.
   * @return A reference to the Fixed object with the minimum value between `a`
   * and `b`.
   */
  static Fixed &min(Fixed &a, Fixed &b);

  /**
   * @brief Maximum function (non-const version).
   *
   * Returns a reference to the Fixed object with the maximum value between `a`
   * and `b`.
   *
   * @param a The first Fixed object.
   * @param b The second Fixed object.
   * @return A reference to the Fixed object with the maximum value between `a`
   * and `b`.
   */
  static Fixed &max(Fixed &a, Fixed &b);

  /**
   * @brief Minimum function (const version).
   *
   * Returns a reference to the Fixed object with the minimum value between `a`
   * and `b`.
   *
   * @param a The first Fixed object.
   * @param b The second Fixed object.
   * @return A reference to the Fixed object with the minimum value between `a`
   * and `b`.
   */
  static const Fixed &min(const Fixed &a, const Fixed &b);

  /**
   * @brief Minimum function (const version).
   *
   * Returns a reference to the Fixed object with the minimum value between `a`
   * and `b`.
   *
   * @param a The first Fixed object.
   * @param b The second Fixed object.
   * @return A reference to the Fixed object with the minimum value between `a`
   * and `b`.
   */
  static const Fixed &max(const Fixed &a, const Fixed &b);

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
