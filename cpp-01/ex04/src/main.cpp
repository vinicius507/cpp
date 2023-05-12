/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:19:47 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/12 18:52:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

static inline void argparsing_error(std::string fed, std::string error) {
  std::cerr << "Error: " << error << std::endl
            << "Usage: " << fed << " FILE SEARCH REAPLACE" << std::endl
            << std::endl
            << "Replaces all occurrences of a string in a file." << std::endl
            << std::endl
            << "Arguments:" << std::endl
            << "  FILE     The file to edited." << std::endl
            << "  SEARCH   The string to be replaced." << std::endl
            << "  REPLACE  The replace string." << std::endl;
}

int main(int argc, char *argv[]) {
  std::string fname;
  std::string search, replace;

  if (argc != 4) {
    argparsing_error(argv[0], "wrong number of arguments.");
    return (1);
  }

  fname = std::string(argv[1]);
  search = std::string(argv[2]);
  replace = std::string(argv[3]);

  std::fstream file(fname);
  if (file.is_open() == false) {
    argparsing_error(argv[0], fname + ": failed to open file.");
    return (1);
  }
  file.close();
  return (0);
}
