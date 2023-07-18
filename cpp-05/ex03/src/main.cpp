/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:24:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/07/18 16:40:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
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

static void testSignRobotomyRequestForm(void) {
  Bureaucrat bob("Bob", 1);
  RobotomyRequestForm form("Marvin");

  bob.signForm(form);
  EXPECT_TRUE(form.isSigned());
}

static void testSignRobotomyRequestFormGradeTooLow(void) {
  Bureaucrat bob("Bob", 73);
  RobotomyRequestForm form("Marvin");

  bob.signForm(form);
  EXPECT_FALSE(form.isSigned());
}

static void testExecuteRobotomyRequestForm(void) {
  Bureaucrat bob("Bob", 1);
  RobotomyRequestForm form("Marvin");

  bob.signForm(form);
  form.execute(bob);
  EXPECT_TRUE(true);
}

static void testExecuteRobotomyRequestFormGradeTooLow(void) {
  Bureaucrat bob("Bob", 46);
  RobotomyRequestForm form("Marvin");

  bob.signForm(form);
  EXPECT_EXCEPTION(form.execute(bob), AForm::GradeTooLowException);
}

static void testExecuteRobotomyRequestFormFormIsUnsigned(void) {
  Bureaucrat bob("Bob", 1);
  RobotomyRequestForm form("Marvin");

  EXPECT_EXCEPTION(form.execute(bob), AForm::FormIsUnsigned);
}

static void testBureaucratExecuteRobotomyRequestForm(void) {
  Bureaucrat bob("Bob", 1);
  RobotomyRequestForm form("Marvin");

  bob.signForm(form);
  bob.executeForm(form);
  EXPECT_TRUE(true);
}

static void testBureaucratExecuteRobotomyRequestForm50Percent(void) {
  Bureaucrat bob("Bob", 1);
  RobotomyRequestForm form("Marvin");

  bob.signForm(form);
  for (int i = 0; i < 10; i++) {
    bob.executeForm(form);
  }
  EXPECT_TRUE(true);
}

static void testBureaucratExecuteRobotomyRequestFormGradeTooLow(void) {
  Bureaucrat notBob("Not Bob", 46);
  RobotomyRequestForm form("Marvin");

  notBob.signForm(form);
  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

static void testBureaucratExecuteRobotomyRequestFormFormIsUnsigned(void) {
  Bureaucrat notBob("Not Bob", 8);
  RobotomyRequestForm form("Marvin");

  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

static void testWeakBureaucratRobotomyRequestForm(void) {
  Bureaucrat notBob("Not Bob", 150);
  RobotomyRequestForm form("Marvin");

  notBob.signForm(form);
  notBob.executeForm(form);
  EXPECT_FALSE(false);
}

static void testInternCreateUnknownForm(void) {
  AForm *form;
  Intern intern;

  form = intern.makeForm("Unknown form", "Marvin");

  EXPECT(form, NULL);

  if (form != NULL)
    delete form;
}

static void testInternCreatePresidentialPardonForm(void) {
  AForm *form;
  Intern intern;
  bool isPresidenitalPardonForm = false;

  form = intern.makeForm("presidential pardon", "Marvin");
  isPresidenitalPardonForm =
      dynamic_cast<PresidentialPardonForm *>(form) != NULL;

  EXPECT_TRUE(isPresidenitalPardonForm);

  delete form;
}

static void testInternCreateRobotomyRequestForm(void) {
  AForm *form;
  Intern intern;
  bool isRobotomyRequest = false;

  form = intern.makeForm("robotomy request", "Marvin");
  isRobotomyRequest = dynamic_cast<RobotomyRequestForm *>(form) != NULL;

  EXPECT_TRUE(isRobotomyRequest);

  delete form;
}

static void testInternCreateShrubberyCreationForm(void) {
  AForm *form;
  Intern intern;
  bool isShrubberyCreationForm = false;

  form = intern.makeForm("shrubbery creation", "Marvin");
  isShrubberyCreationForm = dynamic_cast<ShrubberyCreationForm *>(form) != NULL;

  EXPECT_TRUE(isShrubberyCreationForm);

  delete form;
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

  TEST(testSignRobotomyRequestForm);
  TEST(testSignRobotomyRequestFormGradeTooLow);

  TEST(testExecuteRobotomyRequestForm);
  TEST(testExecuteRobotomyRequestFormGradeTooLow);
  TEST(testExecuteRobotomyRequestFormFormIsUnsigned);

  TEST(testBureaucratExecuteRobotomyRequestForm);
  TEST(testBureaucratExecuteRobotomyRequestForm50Percent);
  TEST(testBureaucratExecuteRobotomyRequestFormGradeTooLow);
  TEST(testBureaucratExecuteRobotomyRequestFormFormIsUnsigned);

  TEST(testWeakBureaucratRobotomyRequestForm);

  TEST(testInternCreateUnknownForm);
  TEST(testInternCreatePresidentialPardonForm);
  TEST(testInternCreateRobotomyRequestForm);
  TEST(testInternCreateShrubberyCreationForm);
  return (0);
}
