/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:12:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 16:51:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * @brief Generates an object derived from the Base class (one of A, B or C).
 *
 * @return A pointer to an object derived from Base.
 */
Base *generate(void) {
  int _class;
  Base *randomObj;
  std::string subclasses("ABC");

  _class = rand() % 3;
  switch (_class) {
  case (0):
    randomObj = new A();
    break;
  case (1):
    randomObj = new B();
    break;
  case (2):
    randomObj = new C();
    break;
  default:
    randomObj = NULL;
    break;
  }
  std::cout << "Generated an object of the " << subclasses[_class] << " type."
            << std::endl;
  return (randomObj);
}

/**
 * @brief Tries to identify whether a pointer to a Base object is from A, B or
 * C.
 *
 * @param b A pointer to an object derived from Base.
 */
void identify(Base *b) {
  if (dynamic_cast<A *>(b) != NULL) {
    std::cout << "A" << std::endl;
    return;
  }
  if (dynamic_cast<B *>(b) != NULL) {
    std::cout << "B" << std::endl;
    return;
  }
  if (dynamic_cast<C *>(b) != NULL) {
    std::cout << "C" << std::endl;
    return;
  }
  std::cerr << "Error: invalid pointer type." << std::endl;
}

int main(void) {
  Base *b;

  std::srand((unsigned)time(NULL));
  for (int i = 0; i < 10; i++) {
    b = generate();
    identify(b);
    delete b;
  }
  identify(static_cast<Base *>(NULL));
  return (0);
}
