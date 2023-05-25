/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:33:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 17:44:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"
#include <iostream>

#define N_TESTS 10

int main(void) {
  Point a(0, 0);
  Point b(5, 0);
  Point c(2, 3);

  Point testPoints[N_TESTS] = {
      Point(2, 1), // inside
      Point(3, 4), // outside
      Point(2, 0), // on the boundary
      Point(0, 0), // on vertex a
      Point(5, 0), // on vertex b
      Point(2, 3), // on vertex c
      Point(1, 1), // inside
      Point(3, 1), // inside
      Point(3, 2), // inside
      Point(1, 4)  // outside
  };
  std::string state[2] = {"outside", "inside"};

  std::cout << "Triangle: " << a << ", " << b << ", " << c << std::endl;
  for (int i = 0; i < N_TESTS; i++) {
    bool isInside = bsp(a, b, c, testPoints[i]);

    std::cout << testPoints[i] << " is " << state[isInside] << " the triangle."
              << std::endl;
  }
  return (0);
}
