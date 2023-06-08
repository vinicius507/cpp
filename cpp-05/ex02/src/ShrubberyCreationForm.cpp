/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:26:13 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 17:46:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {
  this->setName("Shrubbery Creation Form Template");
  this->setRequiredSigningGrade(145);
  this->setRequiredExecutionGrade(137);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : target(target) {
  this->setName("Shrubbery Creation Form - " + target);
  this->setRequiredSigningGrade(145);
  this->setRequiredExecutionGrade(137);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : target(other.getTarget()) {
  this->setName(other.getName());
  this->setRequiredSigningGrade(145);
  this->setRequiredExecutionGrade(137);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    this->setName(other.getName());
    this->setTarget(other.getTarget());
  }
  return (*this);
}

const std::string &ShrubberyCreationForm::getTarget(void) const {
  return (this->target);
}

void ShrubberyCreationForm::setTarget(const std::string &_target) {
  const_cast<std::string &>(this->target) = _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  std::ofstream fout;

  if (!this->isSigned()) {
    throw AForm::FormIsUnsigned();
  }
  if (executor.getGrade() > this->getRequiredExecutionGrade()) {
    throw AForm::GradeTooLowException();
  }
  fout.open(target + "_shrubbery");
  if (fout.fail()) {
    throw ShrubberyCreationForm::ShrubberyCreationError();
  }
  fout << "         ; ; ;" << std::endl
       << "       ;        ;  ;     ;;    ;" << std::endl
       << "    ;                 ;         ;  ;" << std::endl
       << "                    ;" << std::endl
       << "                   ;                ;;" << std::endl
       << "   ;          ;            ;              ;" << std::endl
       << "   ;            ';,        ;               ;" << std::endl
       << "   ;              'b      *" << std::endl
       << "    ;              '$    ;;                ;;" << std::endl
       << "   ;    ;           $:   ;:               ;" << std::endl
       << " ;;      ;  ;;      *;  @):        ;   ; ;" << std::endl
       << "              ;     :@,@):   ,;**:'   ;" << std::endl
       << "  ;      ;,         :@@*: ;;**'      ;   ;" << std::endl
       << "           ';o;    ;:(@';@*\"'  ;" << std::endl
       << "   ;  ;       'bq,;;:,@@*'   ,*      ;  ;" << std::endl
       << "              ,p$q8,:@)'  ;p*'      ;" << std::endl
       << "       ;     '  ; '@@Pp@@*'    ;  ;" << std::endl
       << "        ;  ; ;;    Y7'.'     ;  ;" << std::endl
       << "                  :@):." << std::endl
       << "                 .:@:'." << std::endl
       << "               .::(@:.      -Sam Blumenstein-" << std::endl;

  fout.close();
}

const char *ShrubberyCreationForm::ShrubberyCreationError::what(void) const
    throw() {
  return ("the Shrubbery tree file could not be created");
}
