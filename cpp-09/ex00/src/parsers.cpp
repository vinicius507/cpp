/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:59:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/20 14:46:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.hpp"
#include <ctime>
#include <iomanip>
#include <map>
#include <sstream>
#include <stdexcept>

static int getYear(const std::string &dateStr) {
  int year;
  std::istringstream ss(dateStr.substr(0, 4));

  ss >> year;
  if (ss.fail() || !ss.eof() || year < 0) {
    throw std::runtime_error("Invalid date: " + dateStr);
  }
  return (year);
}

static int getMonth(const std::string &dateStr) {
  int month;
  std::istringstream ss(dateStr.substr(5, 2));

  ss >> month;
  if (ss.fail() || !ss.eof() || month < 1 || month > 12) {
    throw std::runtime_error("Invalid date: " + dateStr);
  }
  return (month);
}

static int getDay(const std::string &dateStr, int dayCap) {
  int day;
  std::istringstream ss(dateStr.substr(8, 2));

  ss >> day;
  if (ss.fail() || !ss.eof() || day < 1 || day > dayCap) {
    throw std::runtime_error("Invalid date: " + dateStr);
  }
  return (day);
}

static bool dateFormatIsValid(const std::string &dateStr) {
  const std::string fmt("YYYY-mm-dd");

  if (dateStr.length() < 10) {
    return (false);
  }
  for (int i = 0; i < 10; i++) {
    switch (fmt[i]) {
    case 'Y':
    case 'm':
    case 'd':
      if (!std::isdigit(dateStr[i])) {
        return (false);
      }
      break;
    case '-':
      if (dateStr[i] != '-') {
        return (false);
      }
      break;
    }
  }
  return (true);
}

std::string parseDate(const std::string &dateStr) {
  bool isLeapYear;
  int year, month, day;
  int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (!dateFormatIsValid(dateStr)) {
    throw std::runtime_error("Invalid date format: " + dateStr);
  }
  year = getYear(dateStr);
  isLeapYear = (year % 4 == 0) && (year % 100);
  if (isLeapYear) {
    daysPerMonth[1] += 1;
  }
  month = getMonth(dateStr);
  day = getDay(dateStr, daysPerMonth[month - 1]);
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
