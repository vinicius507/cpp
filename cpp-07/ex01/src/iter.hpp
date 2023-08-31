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

/**
 * @brief Apply a function to each element of an array.
 * 
 * This template function iterates over an array and applies a given function to each element.
 * 
 * @tparam T The type of elements in the array.
 * 
 * @param arr Pointer to the array of elements.
 * @param length The number of elements in the array.
 * @param f Pointer to the function to be applied to each element.
 *           The function should take a reference to an element of type T as its argument.
 */
template <typename T>
void iter(T *arr, size_t length, void (*f)(T &)) {
  for (size_t i = 0; i < length; i++) {
    f(arr[i]);
  }
}

/**
 * @brief Apply a function to each element of an array.
 * 
 * This template function iterates over an array and applies a given function to each element.
 * 
 * @tparam T The type of the const elements in the array.
 * 
 * @param arr Pointer to the array of const elements.
 * @param length The number of const elements in the array.
 * @param f Pointer to the function to be applied to each element.
 *           The function should take a reference to a const element of type T as its argument.
 */
template <typename T>
void iter(const T *arr, size_t length, void (*f)(const T &)) {
  for (size_t i = 0; i < length; i++) {
    f(arr[i]);
  }
}

/**
 * @brief Prints an object to stdout.
 */
template <typename T>
void printValue(T &obj) {
  std::cout << obj << std::endl;
}

#endif // !ITER_HPP
