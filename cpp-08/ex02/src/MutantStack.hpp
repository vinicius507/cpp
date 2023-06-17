/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:22:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/17 18:17:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file MutantStack.hpp
 * @brief Declaration of the MutantStack template class.
 */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

/**
 * @class MutantStack
 * @brief A std::stack with range iterators support.
 *
 * The MutantStack class is a template class that extends the functionality
 * of std::stack by providing support for range iterators. It allows iterating
 * over the elements in the stack using standard iterator interfaces.
 *
 * @tparam T The type of the elements in the MutantStack object.
 */
template <typename T> class MutantStack : public std::stack<T> {
public:
  /**
   * @brief Default constructor for the MutantStack class.
   *
   * Constructs an empty MutantStack object.
   */
  MutantStack<T>(void) : std::stack<T>() {}

  /**
   * @brief Copy constructor for the MutantStack class.
   *
   * Constructs a MutantStack object by copying the contents of another
   * MutantStack object.
   *
   * @param other The MutantStack object to be copied.
   */
  MutantStack<T>(const MutantStack<T> &other) { *this = other; }

  /**
   * @brief Destructor for the MutantStack class.
   */
  ~MutantStack<T>(void) {}

  /**
   * @brief Assignment operator for the MutantStack class.
   *
   * Assigns the contents of another MutantStack object to this object.
   *
   * @param other The MutantStack object to be assigned.
   * @return A reference to this MutantStack object after assignment.
   */
  MutantStack<T> &operator=(const MutantStack<T> &other) {
    if (this != &other) {
      this->std::stack<T>::operator=(other);
    }
    return (*this);
  }

  /**
   * @typedef iterator
   *
   * An iterator type that provides mutable access to the elements of the
   * MutantStack.
   */
  typedef typename std::stack<T>::container_type::iterator iterator;

  /**
   * @typedef const_iterator
   *
   * An iterator type that provides read-only access to the elements of the
   * MutantStack.
   */
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  /**
   * @typedef reverse_iterator
   *
   * A reverse iterator type that provides mutable access to the elements of the
   * MutantStack in reverse order.
   */
  typedef
      typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

  /**
   * @typedef const_reverse_iterator
   *
   * A reverse iterator type that provides read-only access to the elements of
   * the MutantStack in reverse order.
   */
  typedef typename std::stack<T>::container_type::const_reverse_iterator
      const_reverse_iterator;

  /**
   * @brief Returns an iterator pointing to the first element of the
   * MutantStack.
   *
   * @return An iterator pointing to the first element of the MutantStack.
   */
  iterator begin(void) { return (this->c.begin()); }

  /**
   * @brief Returns an iterator referring to the past-the-end element of the
   * MutantStack.
   *
   * @return An iterator referring to the past-the-end element of the
   * MutantStack.
   */
  iterator end(void) { return (this->c.end()); }

  /**
   * @brief Returns a const iterator pointing to the first element of the
   * MutantStack.
   *
   * @return A const iterator pointing to the first element of the MutantStack.
   */
  const_iterator cbegin(void) const { return (this->c.cbegin()); }

  /**
   * @brief Returns a const iterator referring to the past-the-end element of
   * the MutantStack.
   *
   * @return A const iterator referring to the past-the-end element of the
   * MutantStack.
   */
  const_iterator cend(void) const { return (this->c.cend()); }

  /**
   * @brief Returns a reverse iterator pointing to the last element of the
   * MutantStack.
   *
   * @return A reverse iterator pointing to the last element of the MutantStack.
   */
  reverse_iterator rbegin(void) { return (this->c.rbegin()); }

  /**
   * @brief Returns a reverse iterator referring to the element preceding the
   * first element of the MutantStack.
   *
   * @return A reverse iterator referring to the element preceding the first
   * element of the MutantStack.
   */
  reverse_iterator rend(void) { return (this->c.rend()); }

  /**
   * @brief Returns a const reverse iterator pointing to the last element of the
   * MutantStack.
   *
   * @return A const reverse iterator pointing to the last element of the
   * MutantStack.
   */
  const_reverse_iterator crbegin(void) const { return (this->c.crbegin()); }

  /**
   * @brief Returns a const reverse iterator referring to the element preceding
   * the first element of the MutantStack.
   *
   * @return A const reverse iterator referring to the element preceding the
   * first element of the MutantStack.
   */
  const_reverse_iterator crend(void) const { return (this->c.crend()); }
};

#endif // !MUTANTSTACK_HPP
