/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:56:57 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/17 12:45:21 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyFind(T &c, int n) {
  typename T::iterator it = std::find(c.begin(), c.end(), n);
  if (it == c.end()) {
    throw std::out_of_range("Value not found in container");
  }
  return (it);
}

#endif // !EASYFIND_HPP
