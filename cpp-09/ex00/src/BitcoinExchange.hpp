/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:22:48 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/18 15:35:05 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file BitcoinExchange.hpp
 * @brief Declaration for the BitcoinExchange class.
 */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

/**
 * @class BitcoinExchange
 * @brief Represents a Bitcoin exchange service.
 *
 * It provides exchange methods between the currencies BTC and ₳ (a.k.a.
 * Altarians).
 */
class BitcoinExchange {
public:
  /**
   * @brief Default constructor for the BitcoinExchange class.
   *
   * Constructs a BitcoinExchange object with a no exchange rates history.
   */
  BitcoinExchange(void);

  /**
   * @brief Parametrized constructor for the BitcoinExchange class.
   *
   * Constructs a BitcoinExchange object with the specified exchange rates
   * history.
   *
   * @param exchangeRates The exchange rates history for the BitcoinExchange
   * object.
   */
  BitcoinExchange(std::map<std::string, float> &exchangeRates);

  /**
   * @brief Copy constructor for the BitcoinExchange class.
   *
   * Constructs a BitcoinExchange object by copying the contents from another
   * BitcoinExchange object.
   *
   * @param other The BitcoinExchange object to be copied.
   */
  BitcoinExchange(const BitcoinExchange &other);

  /**
   * @brief Destructor for the BitcoinExchange class.
   */
  ~BitcoinExchange(void);

  /**
   * @brief Assignment operator for the BitcoinExchange class.
   *
   * @param other The BitcoinExchange object to be assigned.
   * @return A reference to the BitcoinExchange object.
   */
  BitcoinExchange &operator=(const BitcoinExchange &other);

  /**
   * @brief Static method for parsing a CSV file as a new BitcoinExchange object
   * exchange rates history.
   *
   * @param filename The filename of the CSV file.
   * @return A pointer to the BitcoinExchange object.
   */
  static BitcoinExchange *fromCSV(const std::string &filename);

private:
  std::map<std::string, float> _exchangeRates; /**< The exchange rates
                                   history from the BitcoinExchange object. */

  /**
   * @brief Parses a date of the format YYYY-mm-dd.
   *
   * @param date The date string to be parsed.
   * @return A copy of the date string.
   * @throw std::runtime_error If the provided date string is invalid.
   */
  static std::string parseDate(const std::string &date);

  /**
   * @brief Parses an exchange rate for the BTC.
   *
   * @param exchangeRate The exchange rate string to be parsed.
   * @return The parsed exchange rate as a float.
   * @throw std::runtime_error If the provided exchange rate string is invalid.
   */
  static float parseExchangeRate(const std::string &exchangeRate);
};

#endif // !BITCOINEXCHANGE_HPP
