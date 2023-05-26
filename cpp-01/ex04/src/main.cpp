/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:19:47 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/26 15:19:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringReplace.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

static inline void usage(std::string fed) {
  std::cerr << "Usage: " << fed << " FILE SEARCH REAPLACE" << std::endl;
}

int main(int argc, char *argv[]) {
  std::ifstream ifs;
  std::ofstream ofs;
  std::stringstream ss;

  if (argc != 4) {
    std::cerr << "Error: wrong number of arguments." << std::endl;
    usage(argv[0]);
    return (1);
  }
  ifs.open(argv[1]);
  if (ifs.fail()) {
    std::cerr << "Error: failed to open file: " << argv[1] << std::endl;
    usage(argv[0]);
    return (1);
  }
  ofs.open((std::string(argv[1]) + ".replace").c_str());
  if (ofs.fail()) {
    std::cerr << "Error: failed create replace file: " << argv[1] << std::endl;
    return (1);
  }
  ss << ifs.rdbuf();
  ofs << stringReplace(ss.str(), argv[2], argv[3]);
  ifs.close();
  ofs.close();
  return (0);
}
