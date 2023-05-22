/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:44:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/22 17:02:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
  Harl harl;
  std::string logLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " LEVEL" << std::endl
              << std::endl
              << "  LEVEL  One of DEBUG, INFO, WARNING, ERROR." << std::endl;
    return (1);
  }
  harl.complain(argv[1]);
  return (0);
}
