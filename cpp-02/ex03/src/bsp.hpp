/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:32:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 15:39:21 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
#define BSP_HPP

#include "Point.hpp"

/**
 * @brief Binary Space Partitioning (BSP) function to check if a point is inside
 * a triangle.
 *
 * The `bsp` function performs Binary Space Partitioning to determine whether a
 * given point is inside a triangle formed by three other points (`a`, `b`, and
 * `c`).
 *
 * @param a The first point of the triangle.
 * @param b The first point of the triangle.
 * @param c The first point of the triangle.
 * @param point The point to be checked for containment within the triangle.
 * @return `true` if `point` is inside of the triangle, `false` otherwise.
 */
bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif // !BSP_HPP
