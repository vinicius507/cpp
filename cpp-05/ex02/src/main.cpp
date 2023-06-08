/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:24:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 17:50:44 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
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

static void testSignPresidentialPardonForm(void) {
  Bureaucrat bob("Bob", 1);
  PresidentialPardonForm form("Marvin");

  bob.signForm(form);
  EXPECT_TRUE(form.isSigned());
}

static void testSignPresidentialPardonFormGradeTooLow(void) {
  Bureaucrat bob("Bob", 26);
  PresidentialPardonForm form("Marvin");

  bob.signForm(form);
  EXPECT_FALSE(form.isSigned());
}

static void testExecutePresidentialPardonForm(void) {
  Bureaucrat bob("Bob", 1);
  PresidentialPardonForm form("Marvin");

  bob.signForm(form);
  form.execute(bob);
  EXPECT_TRUE(true);
}

static void testExecutePresidentialPardonFormGradeTooLow(void) {
  Bureaucrat bob("Bob", 10);
  PresidentialPardonForm form("Marvin");

  bob.signForm(form);
  EXPECT_EXCEPTION(form.execute(bob), AForm::GradeTooLowException);
}

static void testExecutePresidentialPardonFormFormIsUnsigned(void) {
  Bureaucrat bob("Bob", 1);
  PresidentialPardonForm form("Marvin");

  EXPECT_EXCEPTION(form.execute(bob), AForm::FormIsUnsigned);
}

static void testBureaucratExecutePresidentialPardonForm(void) {
  Bureaucrat bob("Bob", 1);
  PresidentialPardonForm form("Marvin");

  bob.signForm(form);
  bob.executeForm(form);
  EXPECT_TRUE(true);
}

static void testBureaucratExecutePresidentialPardonFormGradeTooLow(void) {
  Bureaucrat notBob("Not Bob", 8);
  PresidentialPardonForm form("Marvin");

  notBob.signForm(form);
  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

static void testBureaucratExecutePresidentialPardonFormFormIsUnsigned(void) {
  Bureaucrat notBob("Not Bob", 8);
  PresidentialPardonForm form("Marvin");

  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

static void testWeakBureaucratPresidentialPardonForm(void) {
  Bureaucrat notBob("Not Bob", 150);
  PresidentialPardonForm form("Marvin");

  notBob.signForm(form);
  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

static void testSignShrubberyCreationForm(void) {
  Bureaucrat bob("Bob", 1);
  ShrubberyCreationForm form("Marvin");

  bob.signForm(form);
  EXPECT_TRUE(form.isSigned());
}

static void testSignShrubberyCreationFormGradeTooLow(void) {
  Bureaucrat bob("Bob", 146);
  ShrubberyCreationForm form("Marvin");

  bob.signForm(form);
  EXPECT_FALSE(form.isSigned());
}

static void testExecuteShrubberyCreationForm(void) {
  Bureaucrat bob("Bob", 1);
  ShrubberyCreationForm form("Marvin");

  bob.signForm(form);
  form.execute(bob);
  EXPECT_TRUE(true);
}

static void testExecuteShrubberyCreationFormGradeTooLow(void) {
  Bureaucrat bob("Bob", 145);
  ShrubberyCreationForm form("Marvin");

  bob.signForm(form);
  EXPECT_EXCEPTION(form.execute(bob), AForm::GradeTooLowException);
}

static void testExecuteShrubberyCreationFormFormIsUnsigned(void) {
  Bureaucrat bob("Bob", 1);
  ShrubberyCreationForm form("Marvin");

  EXPECT_EXCEPTION(form.execute(bob), AForm::FormIsUnsigned);
}

static void testBureaucratExecuteShrubberyCreationForm(void) {
  Bureaucrat bob("Bob", 1);
  ShrubberyCreationForm form("Marvin");

  bob.signForm(form);
  bob.executeForm(form);
  EXPECT_TRUE(true);
}

static void testBureaucratExecuteShrubberyCreationFormGradeTooLow(void) {
  Bureaucrat notBob("Not Bob", 145);
  ShrubberyCreationForm form("Marvin");

  notBob.signForm(form);
  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

static void testBureaucratExecuteShrubberyCreationFormFormIsUnsigned(void) {
  Bureaucrat notBob("Not Bob", 8);
  ShrubberyCreationForm form("Marvin");

  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

static void testWeakBureaucratShrubberyCreationForm(void) {
  Bureaucrat notBob("Not Bob", 150);
  ShrubberyCreationForm form("Marvin");

  notBob.signForm(form);
  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

int main(void) {
  TEST(testSignPresidentialPardonForm);
  TEST(testSignPresidentialPardonFormGradeTooLow);

  TEST(testExecutePresidentialPardonForm);
  TEST(testExecutePresidentialPardonFormGradeTooLow);
  TEST(testExecutePresidentialPardonFormFormIsUnsigned);

  TEST(testBureaucratExecutePresidentialPardonForm);
  TEST(testBureaucratExecutePresidentialPardonFormGradeTooLow);
  TEST(testBureaucratExecutePresidentialPardonFormFormIsUnsigned);

  TEST(testWeakBureaucratPresidentialPardonForm);

  TEST(testSignShrubberyCreationForm);
  TEST(testSignShrubberyCreationFormGradeTooLow);

  TEST(testExecuteShrubberyCreationForm);
  TEST(testExecuteShrubberyCreationFormGradeTooLow);
  TEST(testExecuteShrubberyCreationFormFormIsUnsigned);

  TEST(testBureaucratExecuteShrubberyCreationForm);
  TEST(testBureaucratExecuteShrubberyCreationFormGradeTooLow);
  TEST(testBureaucratExecuteShrubberyCreationFormFormIsUnsigned);

  TEST(testWeakBureaucratShrubberyCreationForm);
  return (0);
}
