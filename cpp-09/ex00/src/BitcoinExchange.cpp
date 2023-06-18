/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:59:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/18 15:30:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> &exchangeRates)
    : _exchangeRates(exchangeRates) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _exchangeRates(other._exchangeRates) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    this->_exchangeRates = other._exchangeRates;
  }
  return (*this);
}

BitcoinExchange *BitcoinExchange::fromCSV(const std::string &filename) {
  std::string line;
  std::ifstream csv(filename);
  std::map<std::string, float> exchangeRates;

  std::getline(csv, line);
  if ((csv.fail()) || line != "date,exchange_rate") {
    throw std::runtime_error("Invalid CSV file");
  }
  while ((std::getline(csv, line))) {
    std::istringstream iss(line);
    std::string date, exchangeRate;
    if (!(std::getline(iss, date, ',')) or !(std::getline(iss, exchangeRate))) {
      throw std::runtime_error("Invalid CSV file");
    }
    exchangeRates[(parseDate(date))] = parseExchangeRate(exchangeRate);
  }
  return (new BitcoinExchange(exchangeRates));
}

std::string BitcoinExchange::parseDate(const std::string &date) {
  std::istringstream ss(date);
  std::tm tmDate = {};
  ss >> std::get_time(&tmDate, "%Y-%m-%d");

  if ((ss.fail())) {
    throw std::runtime_error("Invalid date: " + date);
  }
  return (date);
}

float BitcoinExchange::parseExchangeRate(const std::string &exchangeRate) {
  float rate;
  std::istringstream ss(exchangeRate);

  if (!(ss >> rate) || ss.fail() || !(ss.eof())) {
    throw std::runtime_error("Invalid exchange rate: " + exchangeRate);
  }
  if (rate < 0.f) {
    throw std::runtime_error(
        "Invalid exchange rate, expected a value higher than 0, got: " +
        exchangeRate);
  }
  return (rate);
}
