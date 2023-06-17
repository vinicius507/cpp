/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:39:15 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/17 16:26:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Span.hpp
 * @brief Declaration for the Span class.
 */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <vector>

/**
 * @class Span
 * @brief A Span is a collection of `N` integers, with methods to locate the
 * smallest and largest spans between each number.
 */
class Span {
public:
  Span(void);

  Span(size_t n);

  Span(const Span &other);

  ~Span(void);

  Span &operator=(const Span &other);

  void addNumber(int n);

  template <class T> void addNumbers(T &numbers) {
    typename T::iterator it;
    size_t vacantNums = this->capacity() - this->size();

    if (this->isFull()) {
      throw SpanIsFullException();
    }
    if (vacantNums < numbers.size()) {
      throw "Err";
    }
    for (it = numbers.begin(); it != numbers.end(); it++) {
      this->_numbers.push_back(*it);
    }
  };

  size_t capacity(void) const;

  size_t size(void) const;

  bool isFull(void) const;

  int shortestSpan(void) const;

  int longestSpan(void) const;

  class SpanIsFullException : public std::exception {
  public:
    const char *what(void) const throw();
  };

private:
  std::vector<int> _numbers;
};

#endif // !SPAN_HPP
