/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:22:55 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 15:31:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {}

Point::~Point(void) {}

Point &Point::operator=(const Point &other) {
  Fixed x, y;

  x = other.getX();
  y = other.getY();
  this->setCoordinates(x, y);
  return (*this);
}

const Fixed &Point::getX(void) const { return (this->x); }

const Fixed &Point::getY(void) const { return (this->y); }

void Point::setCoordinates(const Fixed x, const Fixed y) {
  const_cast<Fixed &>(this->x) = x;
  const_cast<Fixed &>(this->y) = y;
}
