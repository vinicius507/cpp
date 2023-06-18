/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:59:17 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/18 16:29:21 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_HPP
#define PARSERS_HPP

#include <string>

/**
 * @brief Validates a date string a returns a copy of it if it is valid.
 *
 * @param dateStr The date string to be parsed.
 * @return A copy of the date string.
 * @throw std::runtime_error If the date string is invalid.
 */
std::string parseDate(const std::string &dateStr);

/**
 * @brief Parses a float string value.
 *
 * @param floatStr The float string to be parsed.
 * @return The parsed float value.
 * @throw std::runtime_error If the float string is invalid.
 */
float parseFloat(const std::string &floatStr);

#endif // !PARSERS_HPP
