/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:22:29 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 15:00:02 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
    : name(""), signedStatus(false), requiredSigningGrade(150),
      requiredExecutionGrade(150) {}

Form::Form(const std::string &_name)
    : name(_name), signedStatus(false), requiredSigningGrade(150),
      requiredExecutionGrade(150) {}

Form::Form(const Form &other)
    : name(other.getName()), signedStatus(false),
      requiredSigningGrade(other.getRequiredSigningGrade()),
      requiredExecutionGrade(other.getRequiredExecutionGrade()) {}

Form::~Form(void) {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->setName(other.getName());
    this->setRequiredSigningGrade(other.getRequiredSigningGrade());
    this->setRequiredExecutionGrade(other.getRequiredExecutionGrade());
  }
  return (*this);
}

const std::string &Form::getName(void) const { return (this->name); }

int Form::getRequiredSigningGrade(void) const {
  return (this->requiredSigningGrade);
}

int Form::getRequiredExecutionGrade(void) const {
  return (this->requiredExecutionGrade);
}

void Form::setName(const std::string &_name) {
  const_cast<std::string &>(this->name) = _name;
}

void Form::setRequiredSigningGrade(int _grade) {
  if (_grade < 1) {
    throw Form::GradeTooHighException();
  }
  if (_grade > 150) {
    throw Form::GradeTooLowException();
  }
  const_cast<int &>(this->requiredSigningGrade) = _grade;
}

void Form::setRequiredExecutionGrade(int _grade) {
  if (_grade < 1) {
    throw Form::GradeTooHighException();
  }
  if (_grade > 150) {
    throw Form::GradeTooLowException();
  }
  const_cast<int &>(this->requiredExecutionGrade) = _grade;
}

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > this->getRequiredSigningGrade()) {
    throw Form::GradeTooLowException();
  }
  this->signedStatus = true;
}

bool Form::isSigned(void) const { return (this->signedStatus); }

const char *Form::GradeTooHighException::what(void) const throw() {
  return "the grade provided is too high";
}

const char *Form::GradeTooLowException::what(void) const throw() {
  return "the grade provided is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
  out << f.getName() << (f.isSigned() ? "(signed)" : "(unsigned)")
      << ", required signing grade " << f.getRequiredSigningGrade()
      << ", required execution grade " << f.getRequiredExecutionGrade();
  return (out);
}
