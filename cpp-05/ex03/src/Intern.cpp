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
  const std::string formTypes[3] = {"presidential pardon", "robotomy request",
                                    "shrubbery creation"};

  for (formIdx = 0; formIdx < 3; formIdx++) {
    if (formTypes[formIdx] == type)
      break;
  }
  switch (formIdx) {
  case 0:
    return (new PresidentialPardonForm(target));
  case 1:
    return (new RobotomyRequestForm(target));
  case 2:
    return (new ShrubberyCreationForm(target));
  default:
    std::cerr << "Error: " << type << ": unknown form type" << std::endl;
    break;
  }
  return (NULL);
}
