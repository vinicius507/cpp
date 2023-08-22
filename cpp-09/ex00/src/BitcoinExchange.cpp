/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:59:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/20 13:55:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "parsers.hpp"
#include <fstream>
#include <iostream>
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
  std::ifstream csv(filename.c_str());
  std::map<std::string, float> exchangeRates;

  if ((csv.fail()) || !(std::getline(csv, line)) ||
      line != "date,exchange_rate") {
    throw std::runtime_error("Invalid CSV file");
  }
  while ((std::getline(csv, line))) {
    std::istringstream iss(line);
    std::string date, exchangeRate;
    if (!(std::getline(iss, date, ',')) or !(std::getline(iss, exchangeRate))) {
      throw std::runtime_error("Invalid CSV file");
    }
    if ((parseFloat(exchangeRate) < 0.f)) {
      throw std::runtime_error("Invalid exchange rate: " + exchangeRate);
    }
    exchangeRates[(parseDate(date))] = parseFloat(exchangeRate);
  }
  return (new BitcoinExchange(exchangeRates));
}

float BitcoinExchange::exchange(const std::string &date, float amount) {
  std::map<std::string, float>::iterator it;

  it = this->_exchangeRates.find(date);
  if (it != this->_exchangeRates.end()) {
    return (it->second * amount);
  }
  it = this->_exchangeRates.lower_bound(date);
  if (it == this->_exchangeRates.begin()) {
    if (it->first > date) {
      throw std::runtime_error("No exchange rate for/prior to " + date);
    }
    return (it->second * amount);
  }
  it--;
  return (it->second * amount);
}
