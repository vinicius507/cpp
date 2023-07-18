/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:45:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 17:08:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {
  this->setName("Presidential Pardon Form Template");
  this->setRequiredSigningGrade(25);
  this->setRequiredExecutionGrade(5);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm(), target(target) {
  this->setName("Presidential Pardon Form for " + target);
  this->setRequiredSigningGrade(25);
  this->setRequiredExecutionGrade(5);
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(), target(other.getTarget()) {
  this->setName(other.getName());
  this->setRequiredSigningGrade(25);
  this->setRequiredExecutionGrade(5);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    this->setName(other.getName());
    this->setTarget(other.getTarget());
  }
  return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const {
  return (this->target);
}

void PresidentialPardonForm::setTarget(const std::string &_target) {
  const_cast<std::string &>(this->target) = _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!this->isSigned()) {
    throw AForm::FormIsUnsigned();
  }
  if (executor.getGrade() > this->getRequiredExecutionGrade()) {
    throw AForm::GradeTooLowException();
  }
  std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
