/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:03:17 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/14 18:24:18 by vgoncalv         ###   ########.fr       */
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
  try {
    ScalarConverter::convert(argv[1]);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
