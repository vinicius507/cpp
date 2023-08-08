/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:57:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 17:06:28 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/**
 * @brief Swaps the values of two variables of the same type.
 *
 * @tparam T The type of `a` and `b`.
 * @param a The first value of type `T`.
 * @param b The second value of type `T`.
 */
template <typename T> void swap(T &a, T &b) {
  T aux;

  aux = a;
  a = b;
  b = aux;
}

/**
 * @brief Finds the maximum value between two elements.
 *
 * This template function takes two variables of the same type and returns the
 * greatest of them.
 *
 * @tparam T The type of `a` and `b`.
 * @param a The first value of type `T`.
 * @param b The second value of type `T`.
 * @return The maximum value between `a` and `b`.
 */
template <typename T> T max(T a, T b) {
  if (a > b) {
    return (a);
  }
  return (b);
}

/**
 * @brief Finds the minimum value between two elements.
 *
 * This template function takes two variables of the same type and returns the
 * greatest of them.
 *
 * @tparam T The type of `a` and `b`.
 * @param a The first value of type `T`.
 * @param b The second value of type `T`.
 * @return The minimum value between `a` and `b`.
 */
template <typename T> T min(T a, T b) {
  if (a < b) {
    return (a);
  }
  return (b);
}

#endif // !WHATEVER_HPP
