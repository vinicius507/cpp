/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:50 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/14 17:35:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
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
  if (isIntLiteral(literal)) {
    convertInt(literal);
  }
}

bool ScalarConverter::isIntLiteral(const std::string &literal) {
  int i;
  std::istringstream ss(literal);

  return ((ss >> i) && (ss.eof()));
}

void ScalarConverter::convertInt(const std::string &literal) {
  int i;
  std::istringstream ss(literal);

  ss >> i;
  std::cout << "char: " << displayChar(i) << std::endl
            << "int: " << i << std::endl
            << "float: " << i << ".0f" << std::endl
            << "double: " << i << ".0" << std::endl;
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
