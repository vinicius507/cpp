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

/**
 * @brief Find a value in a container of integers and return an iterator to it.
 * 
 * This function searches for a specified integer value within a container of integers and returns an iterator pointing to the found element.
 * 
 * @tparam T The type of the container. It must be a container of integers (e.g., std::vector<int>, std::list<int>).
 * @param c The container to search in.
 * @param n The integer value to search for.
 * @return An iterator pointing to the found element.
 * @throws std::out_of_range If the value is not found in the container.
 * 
 * @note The function uses the std::find algorithm to search for the value in the container.
 *       If the value is not found, an std::out_of_range exception is thrown.
 *       The function is applicable to containers that provide the begin() and end() member functions.
 * 
 * Example usage:
 * @code
 * std::vector<int> numbers = {1, 2, 3, 4, 5};
 * try {
 *     std::vector<int>::iterator it = easyFind(numbers, 3);
 *     // 'it' now points to the element with value 3 in the 'numbers' vector.
 * } catch (const std::out_of_range &ex) {
 *     std::cerr << "Value not found in container." << std::endl;
 * }
 * @endcode
 */
template <typename T>
typename T::iterator easyFind(T &c, int n) {
  typename T::iterator it = std::find(c.begin(), c.end(), n);
  if (it == c.end()) {
    throw std::out_of_range("Value not found in container");
  }
  return (it);
}

#endif // !EASYFIND_HPP
