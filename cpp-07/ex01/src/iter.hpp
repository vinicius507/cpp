/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:17:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 17:33:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <class T> void iter(T *arr, size_t length, void (*f)(T &)) {
  for (size_t i = 0; i < length; i++) {
    f(arr[i]);
  }
}

template <class T> void printValue(T &obj) {
  std::cout << obj << std::endl;
}

#endif // !ITER_HPP
