/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:12:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/15 17:33:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  int _class;
  Base *randomObj;

  _class = rand() % 3;
  switch (_class) {
  case 0:
    randomObj = new A();
    break;
  case 1:
    randomObj = new B();
    break;
  case 2:
    randomObj = new C();
    break;
  default:
    randomObj = NULL;
    break;
  }
  return (randomObj);
}

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
  return (0);
}
