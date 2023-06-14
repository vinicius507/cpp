/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:50 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/14 18:44:56 by vgoncalv         ###   ########.fr       */
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

void ScalarConverter::convertChar(const std::string &literal) {
  char c;

  c = literal[1];
  std::cout << "char: " << displayChar(c) << std::endl
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