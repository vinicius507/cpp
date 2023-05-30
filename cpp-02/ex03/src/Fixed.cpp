/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:52:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 17:34:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : rawBits(0) {}

Fixed::Fixed(const int n) { this->rawBits = n << this->fractionalBits; }

Fixed::Fixed(const float f) {
  this->rawBits = roundf(f * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &other) {
  this->setRawBits(other.getRawBits());
  return (*this);
}

bool Fixed::operator>(const Fixed &other) const {
  return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
  return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
  return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
  return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
  return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
  return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) {
  Fixed res = Fixed(this->toFloat() + other.toFloat());
  return (res);
}

Fixed Fixed::operator-(const Fixed &other) {
  Fixed res = Fixed(this->toFloat() - other.toFloat());
  return (res);
}

Fixed Fixed::operator*(const Fixed &other) {
  Fixed res = Fixed(this->toFloat() * other.toFloat());
  return (res);
}

Fixed Fixed::operator/(const Fixed &other) {
  Fixed res = Fixed(this->toFloat() / other.toFloat());
  return (res);
}

Fixed &Fixed::operator++(void) {
  this->setRawBits(this->getRawBits() + 1);
  return (*this);
}

Fixed &Fixed::operator--(void) {
  this->setRawBits(this->getRawBits() - 1);
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed copy = *this;

  this->setRawBits(this->getRawBits() + 1);
  return (copy);
}

Fixed Fixed::operator--(int) {
  Fixed copy = *this;

  this->setRawBits(this->getRawBits() - 1);
  return (copy);
}

int Fixed::getRawBits(void) const { return (this->rawBits); }

void Fixed::setRawBits(const int rawBits) { this->rawBits = rawBits; }

int Fixed::toInt(void) const { return (this->rawBits >> this->fractionalBits); }

float Fixed::toFloat(void) const {
  return (static_cast<float>(this->rawBits) / (1 << this->fractionalBits));
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a.getRawBits() < b.getRawBits())
    return (a);
  return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a.getRawBits() > b.getRawBits())
    return (a);
  return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() < b.getRawBits())
    return (a);
  return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() > b.getRawBits())
    return (a);
  return (b);
}

std::ostream &operator<<(std::ostream &out, Fixed const &f) {
  out << f.toFloat();
  return (out);
}

Fixed Fixed::abs(void) const {
  Fixed absoluteValue(*this);

  if (this->getRawBits() < 0) {
    absoluteValue.setRawBits(~absoluteValue.getRawBits() + 1);
  }
  return (absoluteValue);
}