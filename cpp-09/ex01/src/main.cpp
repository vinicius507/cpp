/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:54:20 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/19 14:34:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  RPN rpn;

  if (argc != 2) {
    std::cerr << "Error: insufficient arguments" << std::endl;
    return (1);
  }
  try {
    rpn = RPN(argv[1]);
    std::cout << rpn.result() << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (1);
  }
  return (0);
}
