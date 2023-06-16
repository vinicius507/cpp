/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:00:55 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 17:16:28 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " #TEST_CASE << std::endl;                             \
    TEST_CASE;                                                                 \
    std::cout << std::endl;                                                    \
  } while (0)

#define ASSERT_EQUAL(A, B)                                                     \
  do {                                                                         \
    bool ok = A == B;                                                          \
    std::cout << (ok ? "[OK]" : "[KO]") << " ASSERT " #A " == " #B             \
              << std::endl;                                                    \
    if (!ok) {                                                                 \
      std::cout << #A "=" << A << ", " #B "=" << B << std::endl;               \
    }                                                                          \
  } while (0)

static void testsSubject(void) {
  int a = 2;
  int b = 3;

  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

static void testSwapInts(void) {
  int a = 10;
  int b = 42;

  ::swap(a, b);

  ASSERT_EQUAL(a, 42);
  ASSERT_EQUAL(b, 10);
}

static void testSwapStrings(void) {
  std::string a("A");
  std::string b("B");

  ::swap(a, b);

  ASSERT_EQUAL(a, "B");
  ASSERT_EQUAL(b, "A");
}

static void testSwapDoubles(void) {
  double a = 10.5;
  double b = 42.;

  ::swap(a, b);

  ASSERT_EQUAL(a, 42);
  ASSERT_EQUAL(b, 10.5);
}

static void testMinInts(void) {
  int a = 10;
  int b = 42;

  int _min = ::min(a, b);

  ASSERT_EQUAL(_min, 10);
}

static void testMinStrings(void) {
  std::string a("A");
  std::string b("B");

  std::string _min = ::min(a, b);

  ASSERT_EQUAL(_min, "A");
}

static void testMinDoubles(void) {
  double a = 10.5;
  double b = 42.;

  double _min = ::min(a, b);

  ASSERT_EQUAL(_min, 10.5);
}

static void testMaxInts(void) {
  int a = 10;
  int b = 42;

  int _max = ::max(a, b);

  ASSERT_EQUAL(_max, 42);
}

static void testMaxStrings(void) {
  std::string a("A");
  std::string b("B");

  std::string _max = ::max(a, b);

  ASSERT_EQUAL(_max, "B");
}

static void testMaxDoubles(void) {
  double a = 10.5;
  double b = 42.;

  double _max = ::max(a, b);

  ASSERT_EQUAL(_max, 42.);
}

int main(void) {
  TEST(testsSubject());
  TEST(testSwapInts());
  TEST(testSwapStrings());
  TEST(testSwapDoubles());
  TEST(testMinInts());
  TEST(testMinStrings());
  TEST(testMinDoubles());
  TEST(testMaxInts());
  TEST(testMaxStrings());
  TEST(testMaxDoubles());
  return (0);
}
