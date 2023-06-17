/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:39:15 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/17 17:10:29 by vgoncalv         ###   ########.fr       */
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
 * @brief Represents a collection of integers with a certain capacity.
 *
 * It provides methods to calculate the longest and largest spans between its
 * elements.
 */
class Span {
public:
  /**
   * @brief Default constructor for the Span class.
   *
   * Constructs a Span object with a default capacity of 0 elements.
   */
  Span(void);

  /**
   * @brief Parametrized constructor for the Span class.
   *
   * Constructs a Span object with the specified capacity.
   *
   * @param n The number of elements the Span will be capable of storing.
   */
  Span(size_t n);

  /**
   * @brief Copy constructor for the Span class.
   *
   * Constructs a Span object by copying the contents from another Span object.
   *
   * @param other The Span object to be copied.
   */
  Span(const Span &other);

  /**
   * @brief Destructor for the Span class.
   */
  ~Span(void);

  /**
   * @brief Assignment operator for the Span class.
   *
   * @param other The Span object to be assigned.
   * @return A reference to the Span object.
   */
  Span &operator=(const Span &other);

  /**
   * @brief Adds a number to the Span object.
   *
   * @param n The number to be added to the Span object.
   * @throw Span::SpanIsFullException If the Span object is full.
   */
  void addNumber(int n);

  /**
   * @brief Template function to add multiple numbers at once to the Span
   * object.
   *
   * @tparam T The type of the Container holding the numbers.
   * @param numbers The STL Containers which holds the numbers.
   * @throw SpanIsFullException If the Span is already full.
   * @throw NoCapacityException If there is not enough capacity to add all the
   * numbers.
   */
  template <class T> void addNumbers(T &numbers) {
    typename T::iterator it;
    size_t vacantNums = this->capacity() - this->size();

    if (this->isFull()) {
      throw SpanIsFullException();
    }
    if (vacantNums < numbers.size()) {
      throw NoCapacityException();
    }
    for (it = numbers.begin(); it != numbers.end(); it++) {
      this->_numbers.push_back(*it);
    }
  };

  /**
   * @brief Retrieves the total capacity of the Span object.
   *
   * @return The capacity of the Span object.
   */
  size_t capacity(void) const;

  /**
   * @brief Retrieves the number of elements of the Span object.
   *
   * @return The number of elements of the Span object.
   */
  size_t size(void) const;

  /**
   * @brief Checks if the Span object is full.
   *
   * @return `true` if the Span object is Full, otherwise `false`.
   */
  bool isFull(void) const;

  /**
   * @brief Retrieves the shortest span between the numbers of the Span object.
   *
   * @return The shortest span of the Span object.
   */
  int shortestSpan(void) const;

  /**
   * @brief Retrieves the longest span between the numbers of the Span object.
   *
   * @return The longest span of the Span object.
   */
  int longestSpan(void) const;

  /**
   * @class SpanIsFullException
   * @brief Thrown when trying to add numbers to the Span but it is already
   * full.
   */
  class SpanIsFullException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  /**
   * @class NoCapacityException
   * @brief Thrown when trying to add more numbers than the Span object can
   * hold.
   */
  class NoCapacityException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  /**
   * @class NotEnoughValuesException
   * @brief Thrown when trying to calculate the shortest span or longest span of
   * Span object.
   */
  class NotEnoughValuesException : public std::exception {
  public:
    const char *what(void) const throw();
  };

private:
  std::vector<int> _numbers; /**< The numbers of the Span object. */
};

#endif // !SPAN_HPP
