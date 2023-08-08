/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:13:59 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/20 13:02:21 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <functional>
#include <cmath>
#include <limits>
#include <utility>

Span::Span(void) : _numbers(std::vector<int>()) { this->_numbers.reserve(0); }

Span::Span(size_t n) : _numbers(std::vector<int>()) {
  this->_numbers.reserve(n);
}

Span::Span(const Span &other) {
  this->_numbers.reserve(other.capacity());
  this->_numbers = std::vector<int>(other._numbers);
}

Span::~Span(void) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->_numbers.reserve(other.capacity());
    this->_numbers = std::vector<int>(other._numbers);
  }
  return (*this);
}

void Span::addNumber(int n) {
  if (this->isFull()) {
    throw SpanIsFullException();
  }
  this->_numbers.push_back(n);
}

size_t Span::capacity(void) const { return (this->_numbers.capacity()); }

size_t Span::size(void) const { return (this->_numbers.size()); }

bool Span::isFull(void) const { return (this->size() == this->capacity()); }

int Span::shortestSpan(void) const {
  std::vector<int> sorted;
  std::vector<int>::const_iterator it, next;
  int span = std::numeric_limits<int>::max();

  if (this->size() <= 1) {
    throw NotEnoughValuesException();
  }
  sorted = std::vector<int>(this->_numbers);
  std::sort(sorted.begin(), sorted.end(), std::less<int>());
  for (it = this->_numbers.begin(); it != this->_numbers.end(); it++) {
    next = it + 1;
    span = std::min(std::abs(*it - *next), span);
  }
  return (span);
}

int Span::longestSpan(void) const {
  std::vector<int>::const_iterator min, max;

  if (this->size() <= 1) {
    throw NotEnoughValuesException();
  }
  min = std::min_element(this->_numbers.begin(), this->_numbers.end());
  max = std::max_element(this->_numbers.begin(), this->_numbers.end());
  return (*max - *min);
}

const char *Span::SpanIsFullException::what(void) const throw() {
  return ("The Span is full");
}

const char *Span::NoCapacityException::what(void) const throw() {
  return ("The Span has no capacity for the provided numbers");
}

const char *Span::NotEnoughValuesException::what(void) const throw() {
  return ("The Span does not have enough values");
}
