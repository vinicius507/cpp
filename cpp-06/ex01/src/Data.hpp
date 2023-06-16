/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:39:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 16:19:37 by vgoncalv         ###   ########.fr       */
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

std::ostream &operator<<(std::ostream &out, Data &data);

bool operator==(Data &lhs, Data &rhs);

#endif // !DATA_HPP
