/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:24:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 19:02:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iomanip>
#include <iostream>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " << #TEST_CASE << std::endl;                          \
    try {                                                                      \
      TEST_CASE();                                                             \
    } catch (std::exception & e) {                                             \
      std::cerr << e.what() << std::endl;                                      \
    };                                                                         \
    std::cout << std::setw(32) << std::setfill('-') << "" << std::endl;        \
  } while (0)

static void testBureaucratCreateGradeTooHigh(void) {
  Bureaucrat b("Dezano", 0);
}

static void testBureaucratCreateGradeTooLow(void) {
  Bureaucrat b("Dezano", 151);
}

static void testBureaucratSetGradeTooHigh(void) {
  Bureaucrat b("Dezano", 10);

  b.setGrade(-1);
}

static void testBureaucratSetGradeTooLow(void) {
  Bureaucrat b("Dezano", 10);

  b.setGrade(200);
}

static void testBureaucratIncrementGradeTooHigh(void) {
  Bureaucrat b("Dezano", 1);

  b.incrementGrade();
}

static void testBureaucratDecrementGradeTooLow(void) {
  Bureaucrat b("Dezano", 150);

  b.decrementGrade();
}

static void testSetValidGrade(void) {
  Bureaucrat b("Dezano", 10);

  std::cout << b << std::endl;
  b.setGrade(5);
  std::cout << b << std::endl;
}

static void testIncrementGrade(void) {
  Bureaucrat b("Dezano", 10);

  std::cout << b << std::endl;
  b.incrementGrade();
  std::cout << b << std::endl;
}

static void testDecrementGrade(void) {
  Bureaucrat b("Dezano", 10);

  std::cout << b << std::endl;
  b.decrementGrade();
  std::cout << b << std::endl;
}

int main(void) {
  TEST(testBureaucratCreateGradeTooHigh);
  TEST(testBureaucratCreateGradeTooLow);
  TEST(testBureaucratSetGradeTooHigh);
  TEST(testBureaucratSetGradeTooLow);
  TEST(testBureaucratIncrementGradeTooHigh);
  TEST(testBureaucratDecrementGradeTooLow);
  TEST(testSetValidGrade);
  TEST(testIncrementGrade);
  TEST(testDecrementGrade);
}
