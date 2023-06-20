/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:39:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/20 14:57:25 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " << #TEST_CASE << std::endl;                          \
    TEST_CASE;                                                                 \
    std::cout << std::endl;                                                    \
  } while (0)

#define EXPECT(EXPR, VALUE)                                                    \
  do {                                                                         \
    bool ok = ((EXPR) == VALUE);                                               \
    std::cout << (ok ? "[OK]" : "[KO]") << " " #EXPR " == " #VALUE             \
              << std::endl;                                                    \
    if (!ok) {                                                                 \
      std::cout << EXPR << "!=" << VALUE << std::endl;                         \
    }                                                                          \
  } while (0)

#define EXPECT_EXCEPTION(EXPR, EXC)                                            \
  do {                                                                         \
    try {                                                                      \
      EXPR;                                                                    \
      std::cout << "[KO] " #EXPR " did not throw the exception " #EXC          \
                << std::endl;                                                  \
    } catch (std::exception & e) {                                             \
      if (dynamic_cast<EXC *>(&e)) {                                           \
        std::cout << "[OK] " #EXPR " did throw " #EXC ": " << e.what()         \
                  << std::endl;                                                \
      } else {                                                                 \
        std::cout << "[KO] " #EXPR " did not throw " #EXC << std::endl;        \
        std::cout << "Error: " << e.what() << std::endl;                       \
      }                                                                        \
    }                                                                          \
  } while (0)

static void testSubject(void) {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

static void testMutantStackIterator(void) {
  int intArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  MutantStack<int> stack;
  std::vector<int> vec(intArr, intArr + (sizeof(intArr) / sizeof(int)));
  std::vector<int>::iterator expectedIt;
  MutantStack<int>::iterator resultIt;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  expectedIt = vec.begin();
  for (resultIt = stack.begin(); resultIt != stack.end(); resultIt++) {
    EXPECT(*resultIt, *expectedIt);
    expectedIt++;
  }
}

static void testMutantStackReverseIterator(void) {
  int intArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  MutantStack<int> stack;
  std::vector<int> vec(intArr, intArr + (sizeof(intArr) / sizeof(int)));
  std::vector<int>::reverse_iterator expectedIt;
  MutantStack<int>::reverse_iterator resultIt;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  expectedIt = vec.rbegin();
  for (resultIt = stack.rbegin(); resultIt != stack.rend(); resultIt++) {
    EXPECT(*resultIt, *expectedIt);
    expectedIt++;
  }
}

int main(void) {
  TEST(testSubject());
  TEST(testMutantStackIterator());
  TEST(testMutantStackReverseIterator());
  return (0);
}
