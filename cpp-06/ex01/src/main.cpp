/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:29:20 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 16:21:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdint>
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

static void testBatchData(void) {
  Data *records;

  records = new Data[10];
  for (int i = 0; i < 10; i++) {
    uintptr_t ptr;
    Data *rec = &records[i];
    Data *recDeserialized;

    rec->name = "Marvin-" + std::string(1, '0' + i);
    rec->age = i + 42;
    ptr = Serializer::serialize(rec);
    recDeserialized = Serializer::deserialize(ptr);

    ASSERT_EQUAL(*rec, *recDeserialized);
    ASSERT_EQUAL(rec, recDeserialized);
    ASSERT_EQUAL(ptr, Serializer::serialize(recDeserialized));
  }
  delete[] records;
}

int main(void) {
  TEST(testMarvin42());
  TEST(testBatchData());
  return (0);
}
