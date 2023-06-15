/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:24:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/15 17:46:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ScalarConverter.hpp
 * @brief Declaration for the ScalarConverter class.
 */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

/**
 * @class ScalarConverter
 * @brief Static class for a converter for scalar types. It converts an object
 * of type char, int, double or float to all other types.
 */
class ScalarConverter {
public:
  static void convert(const std::string &literal);

private:
  /**
   * @brief Default constructor for the ScalarConverter class.
   */
  ScalarConverter(void);

  /**
   * @brief Copy constructor for the ScalarConverter class.
   *
   * @param other The ScalarConverter object to be copied.
   */
  ScalarConverter(const ScalarConverter &other);

  /**
   * @brief Destructor for the ScalarConverter class.
   */
  ~ScalarConverter(void);

  /**
   * @brief Assignment operator for the ScalarConverter class.
   *
   * @param other The ScalarConverter object to be assigned.
   * @return A reference to the ScalarConverter object.
   */
  ScalarConverter &operator=(const ScalarConverter &other);

  /**
   * @brief Retrieves the scalar type of a C++ literal.
   *
   * @param literal The C++ literal scalar.
   * @return An integer which represents the type of the scalar.
   * @see ScalarTypes
   */
  static int getScalarType(const std::string &literal);

  /**
   * @brief Checks if a string is a char literal.
   *
   * @param literal The C++ literal scalar.
   * @return `true` if the string represents a char literal, otherwise `false`.
   */
  static bool isCharLiteral(const std::string &literal);

  /**
   * @brief Checks if a string is an int literal.
   *
   * @param literal The C++ literal scalar.
   * @return `true` if the string represents an int literal, otherwise `false`.
   */
  static bool isIntLiteral(const std::string &literal);

  /**
   * @brief Checks if a string is a float literal.
   *
   * @param literal The C++ literal scalar.
   * @return `true` if the string represents a float literal, otherwise `false`.
   */
  static bool isFloatLiteral(const std::string &literal);

  /**
   * @brief Checks if a string is a double literal.
   *
   * @param literal The C++ literal scalar.
   * @return `true` if the string represents a double literal, otherwise
   * `false`.
   */
  static bool isDoubleLiteral(const std::string &literal);

  /**
   * @brief Converts an int literal to all other supported scalar types.
   *
   * @param literal The C++ literal to be converted.
   */
  static void convertInt(const std::string &literal);

  /**
   * @brief Converts a char literal to all other supported scalar types.
   *
   * @param literal The C++ literal to be converted.
   */
  static void convertChar(const std::string &literal);

  /**
   * @brief Converts a float literal to all other supported scalar types.
   *
   * @param literal The C++ literal to be converted.
   */
  static void convertFloat(const std::string &literal);

  /**
   * @brief Converts a double literal to all other supported scalar types.
   *
   * @param literal The C++ literal to be converted.
   */
  static void convertDouble(const std::string &literal);

  /**
   * @brief Retrieves the char literal representation of a scalar.
   *
   * @param c The character to be displayed.
   * @return "Impossible" if there's an overflow, "Non displayable" if the char
   * is non printable, or the valid char literal.
   */
  static std::string displayChar(int c);

  /**
   * @brief Checks if a float will overflow an integer.
   *
   * It does so by checking that `f` is within range (INT_MIN - 0.999...,
   * INT_MAX + 0.999...).
   *
   * @param f The float value to be converted.
   * @return `true` if an overflow happens, otherwise `false`.
   */
  static bool floatOverflowsInt(float f);

  /**
   * @brief Checks if a double will overflow an integer.
   *
   * It does so by checking that `f` is within range (INT_MIN - 0.999...,
   * INT_MAX + 0.999...).
   *
   * @param f The double value to be converted.
   * @return `true` if an overflow happens, otherwise `false`.
   */
  static bool doubleOverflowsInt(double d);

  /**
   * @brief Enumeration for the ScalarTypes supported by the ScalarConverter
   * class.
   */
  enum ScalarTypes {
    INVALID = -1,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SCALARTYPES_COUNT,
  };

  /**
   * @class InvalidLiteralException
   * @brief Thrown when an invalid literal is passed as argument.
   */
  class InvalidLiteralException : public std::exception {
  public:
    /**
     * @brief Describes the exception.
     *
     * @return A message describing the exception.
     */
    const char *what(void) const throw();
  };
};

#endif // !SCALARCONVERTER_HPP
