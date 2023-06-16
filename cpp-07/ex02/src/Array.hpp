/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:35:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/16 19:02:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Array.hpp
 * @brief Declaration for the Array template class.
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

/**
 * @class Array<T>
 * @brief Represents an Array of elements of type `T`.
 *
 * @tparam T The type of the elements of the Array.
 */
template <class T> class Array {
public:
  /**
   * @brief Default constructor for the Array template class.
   *
   * Constructs an Array of type `T` with 0 elements.
   */
  Array(void) : _arr(NULL), _length(0){};

  /**
   * @brief Parametrized constructor for the Array template class.
   *
   * Constructs an array with `n` elements, which are the default value for the
   * `T` type.
   *
   * @param n The number of default elements in the array.
   */
  Array(unsigned int n) : _arr(NULL), _length(n) {
    if (n) {
      this->_arr = new T[n]();
    }
  };

  /**
   * @brief Copy constructor for the Array template class.
   *
   * Constructs an Array by copying the elements of another Array.
   *
   * @param other The array to be copied.
   */
  Array(const Array<T> &other) : _arr(NULL), _length(other.size()) {
    size_t size;

    size = this->size();
    if (size) {
      this->_arr = new T[size]();
      for (size_t i = 0; i < size; i++) {
        this->_arr[i] = other[i];
      }
    }
  }

  /**
   * @brief Destructor for the Array class.
   */
  ~Array(void) {
    if (this->size()) {
      delete[] this->_arr;
    }
    this->_arr = NULL;
    this->_length = 0;
  };

  /**
   * @brief Assignment operator for the Array template class.
   *
   * @param other The Array object to be assigned.
   * @return A reference to the Array object.
   */
  Array<T> &operator=(const Array<T> &other) {
    size_t size;

    if (this->size()) {
      delete[] this->_arr;
    }
    size = other.size();
    this->_arr = new T[size]();
    this->_length = size;
    for (size_t i = 0; i < size; i++) {
      this->_arr[i] = other[i];
    }
    return (*this);
  };

  /**
   * @brief Subscript operator to access the elements of the Array template
   * class.
   *
   * @param index The index of the element to access.
   * @return A reference to the element at the specified index.
   * @throws Array::IndexOutOfBounds If the index is out of bounds.
   */
  T &operator[](size_t index) {
    if (index >= this->size()) {
      throw IndexOutOfBounds();
    }
    return (this->_arr[index]);
  };

  /**
   * @brief Subscript operator to access the elements of the Array template
   * class.
   *
   * @param index The index of the element to access.
   * @return A reference to the element at the specified index.
   * @throws Array::IndexOutOfBounds If the index is out of bounds.
   */
  const T &operator[](size_t index) const {
    if (index >= this->size()) {
      throw IndexOutOfBounds();
    }
    return (this->_arr[index]);
  };

  /**
   * @brief Retrieves the number of elements on the Array.
   *
   * @return The number of elements of the Array.
   */
  size_t size(void) const { return (this->_length); };

  /**
   * @class IndexOutOfBounds
   * @brief Thrown when trying to access an element of an Array and the index is
   * out of bounds.
   */
  class IndexOutOfBounds : public std::exception {
  public:
    const char *what(void) const throw() { return ("Index out of bounds"); };
  };

private:
  T *_arr;        /**< A pointer to the first element of the Array. */
  size_t _length; /**< The length of the array. */
};

#endif // !ARRAY_HPP
