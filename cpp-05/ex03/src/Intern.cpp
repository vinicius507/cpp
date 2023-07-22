/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:14:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/07/18 16:38:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other) { *this = other; }

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return (*this);
}

AForm *Intern::makeForm(const std::string type,
                        const std::string target) const {
  int formIdx;
  AForm *form;
  const std::string formTypes[3] = {"presidential pardon", "robotomy request",
                                    "shrubbery creation"};

  for (formIdx = 0; formIdx < 3; formIdx++) {
    if (formTypes[formIdx] == type)
      break;
  }
  switch (formIdx) {
  case 0:
    form = (new PresidentialPardonForm(target));
    break;
  case 1:
    form = (new RobotomyRequestForm(target));
    break;
  case 2:
    form = (new ShrubberyCreationForm(target));
    break;
  default:
    form = NULL;
    break;
  }
  if (form == NULL)
    std::cerr << "Error: " << type << ": unknown form type" << std::endl;
  else
    std::cout << "Intern creates " << type << " form" << std::endl;
  return (form);
}
