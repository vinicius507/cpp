/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:19:47 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/15 16:20:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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

static std::string search_replace(std::string line, std::string search,
                                  std::string replace) {
  std::stringstream buf;
  unsigned long int start_pos, search_pos;

  start_pos = 0;
  search_pos = line.find(search);
  while (search_pos != std::string::npos) {
    buf << line.substr(start_pos, search_pos - start_pos) << replace;

    start_pos = search_pos + search.length();
    search_pos = line.find(search, start_pos);
  }
  buf << line.substr(start_pos) << std::endl;
  return (buf.str());
}

int main(int argc, char *argv[]) {
  std::string fname;
  std::string search, replace;

  if (argc != 4) {
    argparsing_error(argv[0], "wrong number of arguments.");
    return (1);
  }

  fname = argv[1];
  search = argv[2];
  replace = argv[3];
  std::ifstream file(fname);
  if (file.is_open() == false) {
    std::cerr << "Error: failed to open file." << std::endl;
    return (1);
  }

  std::string line;
  std::stringstream res;
  while (std::getline(file, line)) {
    if (file.bad()) {
      std::cerr << "Error: failed to read file." << std::endl;
      return (1);
    }
    res << search_replace(line, search, replace);
  }
  file.close();

  std::ofstream outfile(fname, std::ofstream::trunc);
  if (outfile.is_open() == false) {
    std::cerr << "Error: failed to write modified content." << std::endl;
    return (1);
  }
  outfile << res.rdbuf();
  outfile.close();
  return (0);
}
