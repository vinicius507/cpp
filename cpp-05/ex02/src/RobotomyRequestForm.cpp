/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:37:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/09 14:46:24 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {
  this->setName("Robotomy Request Form Template");
  this->setRequiredSigningGrade(72);
  this->setRequiredExecutionGrade(45);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm(), target(target) {
  this->setName("Robotomy Request Form - " + target);
  this->setRequiredSigningGrade(72);
  this->setRequiredExecutionGrade(45);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(), target(other.getTarget()) {
  this->setName(other.getName());
  this->setRequiredSigningGrade(72);
  this->setRequiredExecutionGrade(45);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

const std::string &RobotomyRequestForm::getTarget(void) const {
  return (this->target);
}

void RobotomyRequestForm::setTarget(const std::string &_target) {
  const_cast<std::string &>(this->target) = _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  static int i;

  if (!this->isSigned()) {
    throw AForm::FormIsUnsigned();
  }
  if (executor.getGrade() > this->getRequiredExecutionGrade()) {
    throw AForm::GradeTooLowException();
  }
  i = !i;
  if (i % 2) {
    std::cout << this->getTarget() << " has been robotomized successfully."
              << std::endl;
    return;
  }
  std::cout << this->getTarget() << " could not be robotomized." << std::endl;
}
