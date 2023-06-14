/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:03:17 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/14 18:19:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

static void usage(const char *pname) {
  std::cerr << "Usage: " << pname << " LITERAL" << std::endl
            << std::endl
            << "Positional Arguments" << std::endl
            << "  LITERAL    A Literal C++ char, int, float or double."
            << std::endl;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    usage(*argv);
    return (1);
  }
  ScalarConverter::convert(argv[1]);
  return (0);
}
