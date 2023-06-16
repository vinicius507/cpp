/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:39:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 16:44:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

/**
 * @class Data
 * @brief Data structure for a Person's record.
 */
struct Data {
  std::string name;
  int age;
};

/**
 * @brief Insertion operator for the Data struct.
 *
 * @param out The output stream.
 * @param data The data object to be inserted.
 */
std::ostream &operator<<(std::ostream &out, Data &data);

/**
 * @brief Equality operator for the Data struct.
 *
 * @param lhs The left hand side of the equality operator.
 * @param rhs  The right hand side of the equality operator.
 * @return `true` if the records names and ages are equal, otherwise `false`.
 */
bool operator==(Data &lhs, Data &rhs);

#endif // !DATA_HPP
