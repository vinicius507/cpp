/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:18:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/18 17:40:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "parsers.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

static void usage(const char *pname) {
  std::cout << "Usage: " << pname << " FILE" << std::endl
            << std::endl
            << "Positional Arguments" << std::endl
            << "  FILE    A BTC exchange history, where each line is of the "
               "format DATE | AMOUNT."
            << std::endl;
}

static void displayExchangeReceiptLine(BitcoinExchange *btc, size_t lineno,
                                       const std::string &line) {
  float amount;
  std::string date;

  if (lineno == 1 && line == "date | value") {
    return;
  }
  if ((line.length()) < 14 or (line.substr(10, 3) == " | ")) {
    throw std::runtime_error("Invalid input line: " + line);
  }
  date = parseDate(line.substr(0, 10));
  amount = parseFloat(line.substr(12));
  if (amount <= 0.f || amount >= 1000.f) {
    throw std::runtime_error(
        "Invalid BTC amount, expected a positive value smaller than 1000");
  }
  std::cout << std::fixed << std::setprecision(2) << date << " => " << amount
            << "BTC = " << btc->exchange(date, amount) << "₳" << std::endl;
}

int main(int argc, char **argv) {
  std::string line;
  std::ifstream f;
  BitcoinExchange *btc;

  if (argc != 2) {
    usage(argv[0]);
    return (1);
  }
  f.open(argv[1]);
  if ((f.fail())) {
    std::cerr << "Error: could not open input file: " << argv[1] << std::endl;
    f.close();
    return (1);
  }
  size_t lineno = 1;
  btc = BitcoinExchange::fromCSV("data/db.csv");
  while ((std::getline(f, line))) {
    try {
      displayExchangeReceiptLine(btc, lineno++, line);
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  f.close();
  delete btc;
  return (0);
}
