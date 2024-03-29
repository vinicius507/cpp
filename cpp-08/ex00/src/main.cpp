/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:27:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/17 13:30:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>
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

static void testIntVectorFind42(void) {
  int intArr[4] = {0, 10, 42, 512};
  std::vector<int> intVec(intArr, intArr + (sizeof(intArr) / sizeof(int)));
  std::vector<int>::iterator ft;

  ft = easyFind(intVec, 42);

  EXPECT(*ft, 42);
}

static void testIntVectorOutOfRangeException(void) {
  int intArr[1] = {0};
  std::vector<int> intVec(intArr, intArr + (sizeof(intArr) / sizeof(int)));

  EXPECT_EXCEPTION((void)easyFind(intVec, 42), std::out_of_range);
}

static void testIntListFind10(void) {
  int intArr[4] = {0, 10, 42, 512};
  std::list<int> intList(intArr, intArr + (sizeof(intArr) / sizeof(int)));
  std::list<int>::iterator ten;

  ten = easyFind(intList, 10);

  EXPECT(*ten, 10);
}

static void testIntListOutOfRangeException(void) {
  int intArr[4] = {0, 10, 42, 512};
  std::list<int> intList(intArr, intArr + (sizeof(intArr) / sizeof(int)));

  EXPECT_EXCEPTION((void)easyFind(intList, 1), std::out_of_range);
}

static void testIntQueueFind42(void) {
  int intArr[4] = {0, 10, 42, 512};
  std::deque<int> intQueue(intArr, intArr + (sizeof(intArr) / sizeof(int)));
  std::deque<int>::iterator ft;

  ft = easyFind(intQueue, 42);

  EXPECT(*ft, 42);
}

static void testIntQuequeOutOfRangeException(void) {
  int intArr[4] = {0, 10, 42, 512};
  std::deque<int> intQueue(intArr, intArr + (sizeof(intArr) / sizeof(int)));

  EXPECT_EXCEPTION((void)easyFind(intQueue, 1), std::out_of_range);
}

static void testStringFindChar(void) {
  std::string str("Hello, 42!");
  std::string::iterator ft;

  ft = easyFind(str, '4');

  EXPECT(*ft, '4');
}

static void testStringOutOfRangeException(void) {
  std::string str("Hello, 42!");
  std::string::iterator ft;

  EXPECT_EXCEPTION((void)easyFind(str, 'F'), std::out_of_range);
}

int main(void) {
  TEST(testIntVectorFind42());
  TEST(testIntVectorOutOfRangeException());
  TEST(testIntListFind10());
  TEST(testIntListOutOfRangeException());
  TEST(testIntQueueFind42());
  TEST(testIntQuequeOutOfRangeException());
  TEST(testStringFindChar());
  TEST(testStringOutOfRangeException());
  return (0);
}
