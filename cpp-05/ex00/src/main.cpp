/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:24:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 15:34:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iomanip>
#include <iostream>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " << #TEST_CASE << std::endl;                          \
    TEST_CASE();                                                               \
    std::cout << std::setw(32) << std::setfill('-') << "" << std::endl;        \
  } while (0)

#define EXPECT_TRUE(EXPR)                                                      \
  do {                                                                         \
    std::cout << (EXPR ? "[OK]" : "[KO]") << " " #EXPR " == true"              \
              << std::endl;                                                    \
  } while (0)

#define EXPECT_FALSE(EXPR)                                                     \
  do {                                                                         \
    std::cout << (!(EXPR) ? "[OK]" : "[KO]") << " " #EXPR " == false"          \
              << std::endl;                                                    \
  } while (0)

#define EXPECT_EXCEPTION(EXPR, EXC)                                            \
  do {                                                                         \
    try {                                                                      \
      EXPR;                                                                    \
      std::cout << "[KO] " #EXPR " did not throw the exception " #EXC          \
                << std::endl;                                                  \
    } catch (std::exception & e) {                                             \
      if (e.what() == EXC().what()) {                                          \
        std::cout << "[OK] " #EXPR " did throw " #EXC << std::endl;            \
      } else {                                                                 \
        std::cout << "[KO] " #EXPR " did not throw " #EXC << std::endl;        \
      }                                                                        \
    }                                                                          \
  } while (0)

#define EXPECT(EXPR, VALUE)                                                    \
  do {                                                                         \
    std::cout << ((EXPR) == VALUE ? "[OK]" : "[KO]")                           \
              << " " #EXPR " == " #VALUE << std::endl;                         \
  } while (0)

static void testBureaucratCreateGradeTooHigh(void) {
  EXPECT_EXCEPTION(Bureaucrat b("Dezano", 0),
                   Bureaucrat::GradeTooHighException);
}

static void testBureaucratCreateGradeTooLow(void) {
  EXPECT_EXCEPTION(Bureaucrat b("Dezano", 151),
                   Bureaucrat::GradeTooLowException);
}

static void testBureaucratSetGradeTooHigh(void) {
  Bureaucrat b("Dezano", 10);

  EXPECT_EXCEPTION(b.setGrade(-1), Bureaucrat::GradeTooHighException);
}

static void testBureaucratSetGradeTooLow(void) {
  Bureaucrat b("Dezano", 10);

  EXPECT_EXCEPTION(b.setGrade(200), Bureaucrat::GradeTooLowException);
}

static void testBureaucratIncrementGradeTooHigh(void) {
  Bureaucrat b("Dezano", 1);

  EXPECT_EXCEPTION(b.incrementGrade(), Bureaucrat::GradeTooHighException);
}

static void testBureaucratDecrementGradeTooLow(void) {
  Bureaucrat b("Dezano", 150);

  EXPECT_EXCEPTION(b.decrementGrade(), Bureaucrat::GradeTooLowException);
}

static void testSetValidGrade(void) {
  Bureaucrat b("Dezano", 10);

  b.setGrade(5);
  EXPECT(b.getGrade(), 5);
}

static void testIncrementGrade(void) {
  Bureaucrat b("Dezano", 10);

  b.incrementGrade();
  EXPECT(b.getGrade(), 9);
}

static void testDecrementGrade(void) {
  Bureaucrat b("Dezano", 10);

  b.decrementGrade();
  EXPECT(b.getGrade(), 11);
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
