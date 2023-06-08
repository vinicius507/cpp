/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:24:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 15:27:12 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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

static void testBureaucratSignsForm(void) {
  Bureaucrat b("Bob", 1);
  Form form("Form");

  b.signForm(form);
  EXPECT_TRUE(form.isSigned());
}

static void testBureaucratSignsFormGradeTooLow(void) {
  Bureaucrat b("Marvin", 150);
  Form form("Form");

  form.setRequiredSigningGrade(1);
  b.signForm(form);
  EXPECT_FALSE(form.isSigned());
}

static void testSetRequiredSigningGradeTooHigh(void) {
  Form form("Form");

  EXPECT_EXCEPTION(form.setRequiredSigningGrade(0),
                   Form::GradeTooHighException);
}

static void testSetRequiredSigningGradeTooLow(void) {
  Form form("Form");

  EXPECT_EXCEPTION(form.setRequiredSigningGrade(151),
                   Form::GradeTooLowException);
}

static void testSetValidRequiredSigningGrade(void) {
  Form form("Form");

  form.setRequiredSigningGrade(10);
  EXPECT(form.getRequiredSigningGrade(), 10);
}

static void testSetRequiredExecutionGradeTooHigh(void) {
  Form form("Form");

  EXPECT_EXCEPTION(form.setRequiredExecutionGrade(0),
                   Form::GradeTooHighException);
}

static void testSetRequiredExecutionGradeTooLow(void) {
  Form form("Form");

  EXPECT_EXCEPTION(form.setRequiredExecutionGrade(151),
                   Form::GradeTooLowException);
}

static void testSetValidRequiredExecutionGrade(void) {
  Form form("Form");

  form.setRequiredExecutionGrade(10);
  EXPECT(form.getRequiredExecutionGrade(), 10);
}

int main(void) {
  TEST(testBureaucratSignsForm);
  TEST(testBureaucratSignsFormGradeTooLow);

  TEST(testSetRequiredSigningGradeTooHigh);
  TEST(testSetRequiredSigningGradeTooLow);
  TEST(testSetValidRequiredSigningGrade);

  TEST(testSetRequiredExecutionGradeTooHigh);
  TEST(testSetRequiredExecutionGradeTooLow);
  TEST(testSetValidRequiredExecutionGrade);
  return (0);
}
