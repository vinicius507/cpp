/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:13:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 17:09:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(void) : name(""), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name) {
  if (_grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (_grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->setName(other.getName());
    this->setGrade(other.getGrade());
  }
  return (*this);
}

const std::string &Bureaucrat::getName(void) const { return (this->name); }

int Bureaucrat::getGrade(void) const { return (this->grade); }

void Bureaucrat::setName(const std::string &_name) {
  const_cast<std::string &>(this->name) = _name;
}

void Bureaucrat::setGrade(int _grade) {
  if (_grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (_grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade = _grade;
}

void Bureaucrat::incrementGrade(void) {
  if (this->grade - 1 < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  this->grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
  if (this->grade + 1 > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade += 1;
}

void Bureaucrat::signForm(AForm &f) const {
  try {
    f.beSigned(*this);
    std::cout << this->getName() << " signed " << f.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " couldn't sign " << f.getName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm &f) const {
  try {
    f.execute(*this);
    std::cout << this->getName() << " executed " << f.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " couldn't execute " << f.getName()
              << " because " << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
  return ("the grade provided is too high.");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
  return ("the grade provided is too low.");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
  out << b.getName() << ", bureaucrat grade " << b.getGrade();
  return (out);
}
