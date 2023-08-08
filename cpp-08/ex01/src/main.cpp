/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:44:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/17 17:14:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
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
  Span sp = Span(5);

  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

static void testShortSpan(void) {
  Span sp = Span(3);

  sp.addNumber(0);
  sp.addNumber(1);
  sp.addNumber(10);

  EXPECT(sp.shortestSpan(), 1);
  EXPECT(sp.longestSpan(), 10);
}

static void testLargeSpan(void) {
  Span sp(12);
  int intArr[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
  std::vector<int> vec(intArr, intArr + (sizeof(intArr) / sizeof(int)));

  sp.addNumbers(vec.begin(), vec.end());

  EXPECT(sp.shortestSpan(), 1);
  EXPECT(sp.longestSpan(), 2047);
}

static void testSpanAddNumberIsFullException(void) {
  Span sp;

  EXPECT_EXCEPTION(sp.addNumber(0), Span::SpanIsFullException);
}

static void testSpanAddNumbersIsFullException(void) {
  Span sp;
  std::vector<int> vec(10, 0);

  EXPECT_EXCEPTION(sp.addNumbers(vec.begin(), vec.end()),
                   Span::SpanIsFullException);
}

static void testSpanAddNumbersNoCapacity(void) {
  Span sp(5);
  std::vector<int> vec(10, 0);

  EXPECT_EXCEPTION(sp.addNumbers(vec.begin(), vec.end()),
                   Span::NoCapacityException);
}

static void testShortestSpanNotEnoughValuesException(void) {
  Span sp(5);

  EXPECT_EXCEPTION(sp.shortestSpan(), Span::NotEnoughValuesException);
}

static void testLongestSpanNotEnoughValuesException(void) {
  Span sp(5);

  EXPECT_EXCEPTION(sp.longestSpan(), Span::NotEnoughValuesException);
}

int main(void) {
  TEST(testSubject());
  TEST(testShortSpan());
  TEST(testLargeSpan());
  TEST(testSpanAddNumberIsFullException());
  TEST(testSpanAddNumbersIsFullException());
  TEST(testSpanAddNumbersNoCapacity());
  TEST(testShortestSpanNotEnoughValuesException());
  TEST(testLongestSpanNotEnoughValuesException());
  return (0);
}
