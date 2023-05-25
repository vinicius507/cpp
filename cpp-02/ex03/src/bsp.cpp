/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:32:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 17:36:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"
#include <iostream>

static Fixed triangleArea(const Point &a, const Point &b, const Point &c) {
  Fixed x1 = a.getX();
  Fixed y1 = a.getY();
  Fixed x2 = b.getX();
  Fixed y2 = b.getY();
  Fixed x3 = c.getX();
  Fixed y3 = c.getY();

  Fixed crossProduct = ((x2 - x1) * (y3 - y1) - ((x3 - x1) * (y2 - y1)));
  return (crossProduct.abs() / Fixed(2));
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  Fixed areaABC = triangleArea(a, b, c);
  Fixed areaPAB = triangleArea(point, a, b);
  Fixed areaPAC = triangleArea(point, a, c);
  Fixed areaPBC = triangleArea(point, b, c);
  bool pointIsVertex = (point == a) || (point == b) || (point == c);
  bool pointIsEdge = (areaABC.getRawBits() == 0 || areaPAB.getRawBits() == 0 ||
                      areaPAC.getRawBits() == 0 || areaPBC.getRawBits() == 0);

  if (pointIsVertex or pointIsEdge) {
    return (false);
  }
  return ((areaPAB + areaPAC + areaPBC) == areaABC);
}
