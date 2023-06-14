/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:24:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/14 16:43:43 by vgoncalv         ###   ########.fr       */
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

  static bool isIntLiteral(const std::string &literal);

  static void convertInt(const std::string &literal);

  static std::string displayChar(int c);

  class InvalidLiteralException : std::exception {
  public:
    const char *what(void) const throw();
  };
};

#endif // !SCALARCONVERTER_HPP
