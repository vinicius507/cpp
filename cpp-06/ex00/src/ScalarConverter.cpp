/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:50 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/15 09:42:05 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return (*this);
}

void ScalarConverter::convert(const std::string &literal) {
  int literalType = getScalarType(literal);

  switch (literalType) {
  case (INT):
    convertInt(literal);
    break;
  case (CHAR):
    convertChar(literal);
    break;
  case (FLOAT):
    convertFloat(literal);
    break;
  case (DOUBLE):
    convertDouble(literal);
    break;
  default:
    throw InvalidLiteralException();
    break;
  }
}

int ScalarConverter::getScalarType(const std::string &literal) {
  if (isCharLiteral(literal)) {
    return (CHAR);
  }
  if (isIntLiteral(literal)) {
    return (INT);
  }
  if (isFloatLiteral(literal)) {
    return (FLOAT);
  }
  if (isDoubleLiteral(literal)) {
    return (DOUBLE);
  }
  return (INVALID);
}

bool ScalarConverter::isCharLiteral(const std::string &literal) {
  if (literal.length() != 3) {
    return (false);
  }
  return (literal.front() == '\'' && literal.back() == '\'');
}

bool ScalarConverter::isIntLiteral(const std::string &literal) {
  int i;
  std::istringstream ss(literal);

  return ((ss >> i) && (ss.eof()));
}

bool ScalarConverter::isFloatLiteral(const std::string &literal) {
  float f;
  std::stringstream ss(literal.substr(0, literal.length() - 1));

  return ((ss >> f) && (ss.eof()) && (literal.back() == 'f'));
}

bool ScalarConverter::isDoubleLiteral(const std::string &literal) {
  double d;
  std::istringstream ss(literal);

  return ((ss >> d) && (ss.eof()));
}

void ScalarConverter::convertChar(const std::string &literal) {
  char c = literal[1];

  std::cout << "char: " << (std::isprint(c) ? literal : "Non displayable")
            << std::endl
            << "int: " << static_cast<int>(c) << std::endl
            << "float: " << static_cast<float>(c) << ".0f" << std::endl
            << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &literal) {
  int i;
  std::istringstream ss(literal);

  ss >> i;
  std::cout << "char: " << displayChar(i) << std::endl
            << "int: " << i << std::endl
            << "float: " << static_cast<float>(i) << ".0f" << std::endl
            << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal) {
  float f;
  std::istringstream ss(literal.substr(0, literal.length() - 1));

  ss >> f;
  std::cout << "char: " << displayChar(f) << std::endl
            << "int: " << static_cast<int>(f) << std::endl
            << "float: " << f << "f" << std::endl
            << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(const std::string &literal) {
  double i;
  std::istringstream ss(literal);

  ss >> i;
  std::cout << "char: " << displayChar(i) << std::endl
            << "int: " << static_cast<int>(i) << std::endl
            << "float: " << static_cast<float>(i) << "f" << std::endl
            << "double: " << i << std::endl;
}

std::string ScalarConverter::displayChar(int c) {
  std::stringstream ss;
  bool charOverflows = (c & 0xff) != c;

  if (charOverflows) {
    return ("Impossible");
  }
  if (!std::isprint(c)) {
    return ("Non displayable");
  }
  ss << "\'" << static_cast<char>(c) << "\'";
  return (ss.str());
}

const char *ScalarConverter::InvalidLiteralException::what(void) const throw() {
  return "Invalid literal provided. Expected a literal of a int, an int, a "
         "float or a double.";
}
