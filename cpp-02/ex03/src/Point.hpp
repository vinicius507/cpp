/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:13:12 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 15:31:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

/**
 * @class Point
 * @brief Represents a Point in 2D space.
 */
class Point {
public:
  /**
   * @brief Default constructor for the Point class.
   *
   * Constructs a Point object with default coordinates (0,0).
   */
  Point(void);

  /**
   * @brief Parametrized constructor for the Point class.
   *
   * Constructs a Point object with the specified coordinates.
   * The coordinates are converted to Fixed number values.
   *
   * @param x The x-coordinate of the point.
   * @param y The y-coordinate of the point.
   */
  Point(const float x, const float y);

  /**
   * @brief Copy constructor for the Point class.
   *
   * Constructs a new Point object by copying the coordinates of another Point
   * object.
   *
   * @param other The Point object to be copied.
   */
  Point(const Point &other);

  /**
   * @brief Destructor for the Point class.
   */
  ~Point(void);

  /**
   * @brief Assignment operator for the Point class.
   *
   * Assigns the value of another Point object to this Point object.
   *
   * @param other The Point object to be assigned.
   * @return A reference to the assigned Point object.
   */
  Point &operator=(const Point &other);

  /**
   * @brief Retrieves the x-coordinate of the Point.
   *
   * @return The x-coordinate of the Point.
   */
  const Fixed &getX(void) const;

  /**
   * @brief Retrieves the y-coordinate of the Point.
   *
   * @return The y-coordinate of the Point.
   */
  const Fixed &getY(void) const;

  /**
   * @brief Sets the coordinates of the Point.
   *
   * @param x The new x-coordinate of the Point.
   * @param y The new y-coordinate of the Point.
   */
  void setCoordinates(const Fixed x, const Fixed y);

private:
  const Fixed x; /**< The x-coordinate of the Point. */
  const Fixed y; /**< The y-coordinate of the Point. */
};

#endif // !POINT_HPP
