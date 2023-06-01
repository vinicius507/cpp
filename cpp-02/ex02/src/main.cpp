/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:33:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/01 16:15:57 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
#include <iostream>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " << #TEST_CASE << std::endl;                          \
    TEST_CASE();                                                               \
    std::cout << std::setw(32) << std::setfill('-') << "" << std::endl;        \
  } while (0)

static void subjectTests(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
}

static void arithimeticTests(void) {
  Fixed a(3.5f);
  Fixed b(2);
  Fixed res;

  res = a + b;
  std::cout << "[Addition]" << std::endl
            << "rawBits=" << res.getRawBits() << std::endl
            << "toFloat=" << res.toFloat() << std::endl;
  res = a - b;
  std::cout << "[Subtraction]" << std::endl
            << "rawBits=" << res.getRawBits() << std::endl
            << "toFloat=" << res.toFloat() << std::endl;
  res = a * b;
  std::cout << "[Multiplication]" << std::endl
            << "rawBits=" << res.getRawBits() << std::endl
            << "toFloat=" << res.toFloat() << std::endl;
  res = a / b;
  std::cout << "[Division]" << std::endl
            << "rawBits=" << res.getRawBits() << std::endl
            << "toFloat=" << res.toFloat() << std::endl;
}

int main(void) {
  TEST(subjectTests);
  TEST(arithimeticTests);
  return (0);
}
