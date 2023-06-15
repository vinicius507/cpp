/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:24:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/15 11:42:07 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &literal);

private:
  ScalarConverter(void);

  ScalarConverter(const ScalarConverter &other);

  ~ScalarConverter(void);

  ScalarConverter &operator=(const ScalarConverter &other);

  static int getScalarType(const std::string &literal);

  static bool isCharLiteral(const std::string &literal);

  static bool isIntLiteral(const std::string &literal);

  static bool isFloatLiteral(const std::string &literal);

  static bool isDoubleLiteral(const std::string &literal);

  static void convertInt(const std::string &literal);

  static void convertChar(const std::string &literal);

  static void convertFloat(const std::string &literal);

  static void convertDouble(const std::string &literal);

  static std::string displayChar(int c);

  static bool floatOverflowsInt(float f);

  static bool doubleOverflowsInt(double d);

  enum ScalarTypes {
    INVALID = -1,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SCALARTYPES_COUNT,
  };

  class InvalidLiteralException : public std::exception {
  public:
    const char *what(void) const throw();
  };
};

#endif // !SCALARCONVERTER_HPP
