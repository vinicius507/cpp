/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/15 15:55:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

std::ostream &operator<<(std::ostream &out, Data &data) {
  out << "Data{i: " << data.i << ", j: " << data.j << "}";
  return (out);
}
