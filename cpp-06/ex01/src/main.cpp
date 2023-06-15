/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:29:20 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/15 16:28:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdint>
#include <iostream>
#include <limits>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " #TEST_CASE << std::endl;                             \
    TEST_CASE();                                                               \
  } while (0)

#define ASSERT_EQUAL(A, B)                                                     \
  do {                                                                         \
    bool ok = A == B;                                                          \
    std::cout << (ok ? "[OK]" : "[KO]") << " ASSERT " #A " == " #B             \
              << std::endl;                                                    \
    if (!ok) {                                                                 \
      std::cout << "Got: " << A << " " << B << std::endl;                      \
    }                                                                          \
  } while (0)

static void testZeroedData(void) {
  Data data = {0, 0};
  Data *derivedData;
  uintptr_t rawData;
  uintptr_t derivedRawData;

  rawData = Serializer::serialize(&data);
  derivedData = Serializer::deserialize(rawData);
  derivedRawData = Serializer::serialize(&data);

  ASSERT_EQUAL(data.i, derivedData->i);
  ASSERT_EQUAL(data.j, derivedData->j);
  ASSERT_EQUAL(rawData, derivedRawData);
  ASSERT_EQUAL(&data, derivedData);
}

static void testPositiveData(void) {
  Data data = {10, 42};
  Data *derivedData;
  uintptr_t rawData;
  uintptr_t derivedRawData;

  rawData = Serializer::serialize(&data);
  derivedData = Serializer::deserialize(rawData);
  derivedRawData = Serializer::serialize(&data);

  ASSERT_EQUAL(data.i, derivedData->i);
  ASSERT_EQUAL(data.j, derivedData->j);
  ASSERT_EQUAL(rawData, derivedRawData);
  ASSERT_EQUAL(&data, derivedData);
}

static void testNegativeData(void) {
  Data data = {-10, -42};
  Data *derivedData;
  uintptr_t rawData;
  uintptr_t derivedRawData;

  rawData = Serializer::serialize(&data);
  derivedData = Serializer::deserialize(rawData);
  derivedRawData = Serializer::serialize(&data);

  ASSERT_EQUAL(data.i, derivedData->i);
  ASSERT_EQUAL(data.j, derivedData->j);
  ASSERT_EQUAL(rawData, derivedRawData);
  ASSERT_EQUAL(&data, derivedData);
}

static void testIntMaxIntMin(void) {
  Data data = {std::numeric_limits<int>::max(),
               std::numeric_limits<int>::min()};
  Data *derivedData;
  uintptr_t rawData;
  uintptr_t derivedRawData;

  rawData = Serializer::serialize(&data);
  derivedData = Serializer::deserialize(rawData);
  derivedRawData = Serializer::serialize(&data);

  ASSERT_EQUAL(data.i, derivedData->i);
  ASSERT_EQUAL(data.j, derivedData->j);
  ASSERT_EQUAL(rawData, derivedRawData);
  ASSERT_EQUAL(&data, derivedData);
}

int main(void) {
  TEST(testZeroedData);
  TEST(testPositiveData);
  TEST(testNegativeData);
  TEST(testIntMaxIntMin);
  return (0);
}
