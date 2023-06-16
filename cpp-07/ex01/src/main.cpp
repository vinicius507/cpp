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

int main(void) {
  TEST(testIntArray());
  TEST(testDoubleArray());
  TEST(testStringArray());
  return (0);
}
