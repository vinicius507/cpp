/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:01:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/22 16:51:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  int logLevel;
  std::string logLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*handlers[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                     &Harl::error, &Harl::invalid};

  for (logLevel = 0; logLevel < 4; logLevel++) {
    if (logLevels[logLevel] == level) {
      break;
    }
  }
  (this->*handlers[logLevel])();
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
  std::cerr << "❓INVALID" << std::endl
            << "Level what? You can't even select a decent level?!"
            << std::endl;
}
