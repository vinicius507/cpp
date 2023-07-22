/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:22:29 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 15:00:02 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
    : name(""), signedStatus(false), requiredSigningGrade(150),
      requiredExecutionGrade(150) {}

AForm::AForm(const std::string &_name)
    : name(_name), signedStatus(false), requiredSigningGrade(150),
      requiredExecutionGrade(150) {}

AForm::AForm(const AForm &other)
    : name(other.getName()), signedStatus(false),
      requiredSigningGrade(other.getRequiredSigningGrade()),
      requiredExecutionGrade(other.getRequiredExecutionGrade()) {}

AForm::~AForm(void) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->setName(other.getName());
    this->setRequiredSigningGrade(other.getRequiredSigningGrade());
    this->setRequiredExecutionGrade(other.getRequiredExecutionGrade());
  }
  return (*this);
}

const std::string &AForm::getName(void) const { return (this->name); }

int AForm::getRequiredSigningGrade(void) const {
  return (this->requiredSigningGrade);
}

int AForm::getRequiredExecutionGrade(void) const {
  return (this->requiredExecutionGrade);
}

void AForm::setName(const std::string &_name) {
  const_cast<std::string &>(this->name) = _name;
}

void AForm::setRequiredSigningGrade(int _grade) {
  if (_grade < 1) {
    throw AForm::GradeTooHighException();
  }
  if (_grade > 150) {
    throw AForm::GradeTooLowException();
  }
  const_cast<int &>(this->requiredSigningGrade) = _grade;
}

void AForm::setRequiredExecutionGrade(int _grade) {
  if (_grade < 1) {
    throw AForm::GradeTooHighException();
  }
  if (_grade > 150) {
    throw AForm::GradeTooLowException();
  }
  const_cast<int &>(this->requiredExecutionGrade) = _grade;
}

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > this->getRequiredSigningGrade()) {
    throw AForm::GradeTooLowException();
  }
  this->signedStatus = true;
}

bool AForm::isSigned(void) const { return (this->signedStatus); }

const char *AForm::GradeTooHighException::what(void) const throw() {
  return "the grade provided is too high";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
  return "the grade provided is too low";
}

const char *AForm::FormIsUnsigned::what(void) const throw() {
  return "the form is unsigned";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
  out << f.getName() << (f.isSigned() ? "(signed)" : "(unsigned)")
      << ", required signing grade " << f.getRequiredSigningGrade()
      << ", required execution grade " << f.getRequiredExecutionGrade();
  return (out);
}
