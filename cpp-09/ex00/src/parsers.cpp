/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:59:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/18 16:29:28 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

std::string parseDate(const std::string &dateStr) {
  std::istringstream ss(dateStr);
  std::tm tmDate = {};
  ss >> std::get_time(&tmDate, "%Y-%m-%d");

  if ((ss.fail())) {
    throw std::runtime_error("Invalid date: " + dateStr);
  }
  return (dateStr);
}

float parseFloat(const std::string &floatStr) {
  float f;
  std::istringstream ss(floatStr);

  if (!(ss >> f) || ss.fail() || !(ss.eof())) {
    throw std::runtime_error("Invalid exchange rate: " + floatStr);
  }
  return (f);
}
