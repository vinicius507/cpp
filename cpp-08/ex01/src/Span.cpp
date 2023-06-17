/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:13:59 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/17 15:53:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>
#include <limits>
#include <utility>

Span::Span(void) : _capacity(0), _numbers(std::vector<int>()) {}

Span::Span(size_t n) : _capacity(n), _numbers(std::vector<int>()) {}

Span::Span(const Span &other)
    : _capacity(other.capacity()), _numbers(std::vector<int>(other._numbers)) {}

Span::~Span(void) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    const_cast<size_t &>(this->_capacity) = other.capacity();
    this->_numbers = std::vector<int>(other._numbers);
  }
  return (*this);
}

void Span::addNumber(int n) {
  if (this->isFull()) {
    throw "Err";
  }
  this->_numbers.push_back(n);
}

size_t Span::capacity(void) const { return (this->_capacity); }

size_t Span::size(void) const { return (this->_numbers.size()); }

bool Span::isFull(void) const { return (this->size() == this->capacity()); }

int Span::shortestSpan(void) const {
  int span = std::numeric_limits<int>::max();
  std::vector<int>::const_iterator it, next;

  if (this->size() <= 1) {
    throw "Err";
  }

  for (it = this->_numbers.begin(); it != this->_numbers.end(); it++) {
    next = std::next(it, 1);
    if (next == this->_numbers.end()) {
      break;
    }
    if (std::abs(*next - *it) < span) {
      span = std::abs(*next - *it);
    }
  }
  return (span);
}

int Span::longestSpan(void) const {
  int span = 0;
  std::vector<int>::const_iterator it, next;

  if (this->size() <= 1) {
    throw "Err";
  }

  for (it = this->_numbers.begin(); it != this->_numbers.end(); it++) {
    next = std::next(it, 1);
    if (next == this->_numbers.end()) {
      break;
    }
    if (std::abs(*next - *it) > span) {
      span = *next - *it;
    }
  }
  return (span);
}
