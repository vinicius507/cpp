/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:44:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/17 16:34:58 by vgoncalv         ###   ########.fr       */
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
  EXPECT(sp.longestSpan(), 9);
}

static void testLargeSpan(void) {
  Span sp(12);
  int intArr[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
  std::vector<int> vec(intArr, intArr + (sizeof(intArr) / sizeof(int)));

  sp.addNumbers(vec);

  EXPECT(sp.shortestSpan(), 1);
  EXPECT(sp.longestSpan(), 1024);
}

static void testSpanAddNumberIsFullException(void) {
  Span sp;

  EXPECT_EXCEPTION(sp.addNumber(0), Span::SpanIsFullException);
}

static void testSpanAddNumbersIsFullException(void) {
  Span sp;
  std::vector<int> vec(10, 0);

  EXPECT_EXCEPTION(sp.addNumbers(vec), Span::SpanIsFullException);
}

int main(void) {
  TEST(testSubject());
  TEST(testShortSpan());
  TEST(testLargeSpan());
  TEST(testSpanAddNumberIsFullException());
  TEST(testSpanAddNumbersIsFullException());
  return (0);
}
