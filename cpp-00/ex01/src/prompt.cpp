/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:31:38 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/22 15:28:20 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.hpp"
#include <iostream>

std::string prompt(std::string prefix) {
  std::string ans;

  std::cout << prefix;
  std::getline(std::cin, ans);

  if (std::cin.eof()) {
    std::cerr << std::endl << "Error: EOF reached while reading standard input";
    exit(1);
  }

  if (std::cin.fail()) {
    std::cerr << "Error: input failure while reading standard input";
    exit(1);
  }
  return ans;
}
