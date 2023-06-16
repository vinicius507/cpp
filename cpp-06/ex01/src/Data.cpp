/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 16:20:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

std::ostream &operator<<(std::ostream &out, Data &data) {
  out << "Data{name: " << data.name << ", age: " << data.age << "}";
  return (out);
}

bool operator==(Data &lhs, Data &rhs) {
  return ((lhs.name == rhs.name) && (lhs.age == rhs.age));
}
