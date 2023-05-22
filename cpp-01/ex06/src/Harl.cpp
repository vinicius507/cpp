/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:44:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/22 17:03:12 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  int logLevel;
  std::string logLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (logLevel = 0; logLevel < 4; logLevel++) {
    if (logLevels[logLevel] == level) {
      break;
    }
  }

  switch (logLevel) {
  case 0:
    this->debug();
  case 1:
    this->info();
  case 2:
    this->warning();
  case 3:
    this->error();
    break;
  default:
    this->invalid();
    break;
  }
}

void Harl::debug(void) {
  std::cerr
      << "🧐 DEBUG" << std::endl
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cerr << "ℹ️ INFO" << std::endl
            << "I cannot believe adding extra bacon costs more money. You "
               "didn’t put enough bacon in my burger! If you did, I wouldn’t "
               "be asking for more!"
            << std::endl;
}

void Harl::warning(void) {
  std::cerr
      << "⚠️ WARNING" << std::endl
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error(void) {
  std::cerr << "❌ ERROR" << std::endl
            << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::invalid(void) {
  std::cerr << "[ Probably complaining about insignificant problems ]"
            << std::endl;
}
