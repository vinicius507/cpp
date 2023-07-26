/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:29:20 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/20 12:53:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>
#include <limits>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " #TEST_CASE << std::endl;                             \
    TEST_CASE;                                                                 \
  } while (0)

#define ASSERT_EQUAL(A, B)                                                     \
  do {                                                                         \
    bool ok = A == B;                                                          \
    std::cout << #A "=" << A << ", " #B "=" << B << std::endl;                 \
    std::cout << (ok ? "[OK]" : "[KO]") << " ASSERT " #A " == " #B             \
              << std::endl;                                                    \
    if (!ok) {                                                                 \
      std::cout << "Got: " << A << " " << B << std::endl;                      \
    }                                                                          \
    std::cout << std::endl;                                                    \
  } while (0)

static void testMarvin42(void) {
  Data data = {"Marvin", 42};
  Data *derivedData;
  uintptr_t rawData;
  uintptr_t derivedRawData;

  rawData = Serializer::serialize(&data);
  derivedData = Serializer::deserialize(rawData);
  derivedRawData = Serializer::serialize(&data);

  ASSERT_EQUAL(data, *derivedData);
  ASSERT_EQUAL(&data, derivedData);
  ASSERT_EQUAL(rawData, derivedRawData);
}

int main(void) {
  TEST(testMarvin42());
  return (0);
}
