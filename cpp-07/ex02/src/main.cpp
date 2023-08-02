/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:59:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 19:01:13 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

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
      if (dynamic_cast<EXC *>(&e) != NULL) {                                   \
        std::cout << "[OK] " #EXPR " did throw " #EXC << std::endl;            \
      } else {                                                                 \
        std::cout << "[KO] " #EXPR " did not throw " #EXC << std::endl;        \
      }                                                                        \
    }                                                                          \
  } while (0)

void testEmptyArray(void) {
  Array<char> arr;

  EXPECT(arr.size(), 0);
}

void testSmallDefaultArray(void) {
  Array<int> arr(3);

  EXPECT(arr.size(), 3);
  EXPECT(arr[0], 0);
  EXPECT(arr[1], 0);
  EXPECT(arr[2], 0);
}

void testLargeDefaultArray(void) {
  Array<int> arr(42);

  EXPECT(arr.size(), 42);
  for (size_t i = 0; i < arr.size(); i++) {
    EXPECT(arr[i], 0);
  }
}

void testIndexOutOfBounds(void) {
  Array<int> arr;

  EXPECT_EXCEPTION(arr[0], Array<int>::IndexOutOfBounds);
}

void testCopyConstructor(void) {
  Array<int> arr(5);
  Array<int> arr2(arr);

  arr2[0] = 1;

  EXPECT(arr.size(), arr2.size());
  EXPECT(arr[0], 0);
  EXPECT(arr2[0], 1);
  for (size_t i = 1; i < arr2.size(); i++) {
    EXPECT(arr[i], arr2[i]);
  }
}

void testAssignmentOperator(void) {
  Array<int> arr(5);
  Array<int> arr2 = arr;

  arr2[0] = 1;

  EXPECT(arr.size(), arr2.size());
  EXPECT(arr[0], 0);
  EXPECT(arr2[0], 1);
  for (size_t i = 1; i < arr2.size(); i++) {
    EXPECT(arr[i], arr2[i]);
  }
}

int main(void) {
  TEST(testEmptyArray());
  TEST(testSmallDefaultArray());
  TEST(testLargeDefaultArray());
  TEST(testIndexOutOfBounds());
  TEST(testIndexOutOfBounds());
  TEST(testCopyConstructor());
  TEST(testAssignmentOperator());
  return (0);
}
