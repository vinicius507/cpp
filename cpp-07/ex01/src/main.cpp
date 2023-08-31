/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:23:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 17:33:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " #TEST_CASE << std::endl;                             \
    TEST_CASE;                                                                 \
    std::cout << std::endl;                                                    \
  } while (0)

static void testIntArray(void) {
  int arr[10];

  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }

  iter(arr, 10, ::printValue);
}

static void testDoubleArray(void) {
  double arr[10];

  for (int i = 0; i < 10; i++) {
    arr[i] = static_cast<double>(i);
  }

  iter(arr, 10, ::printValue);
}

static void testStringArray(void) {
  std::string arr[10];

  for (int i = 0; i < 10; i++) {
    arr[i] = "Marvin-" + std::string(1, '0' + i);
  }

  iter(arr, 10, ::printValue);
}

static void testConstVariable(void) {
  const int arr[10] = {0};

  iter(arr, 10, ::printValue<const int>);
}

class Test {
public:
  Test(void) {
    this->_n = objectCount;
    objectCount++;
  }
  int getN(void) const { return (this->_n); }
private:
  int _n;
  static int objectCount;
};
int Test::objectCount = 0;

std::ostream &operator<<(std::ostream &out, const Test &test) {
  out << "Test(n="<< test.getN() << ")";
  return (out);
}

static void testObject(void) {
  Test arr[10];

  iter(arr, 10, ::printValue<Test>);
}

static void testConstObject(void) {
  const Test arr[10];

  iter(arr, 10, ::printValue<const Test>);
}

static void testConstCorrectness(void) {
  int arr[10] = {0};

  iter(arr, 10, ::printValue<const int>);
}

int main(void) {
  TEST(testIntArray());
  TEST(testDoubleArray());
  TEST(testStringArray());
  TEST(testConstVariable());
  TEST(testObject());
  TEST(testConstObject());
  TEST(testConstCorrectness());
  return (0);
}
