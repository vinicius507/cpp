/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:49:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/20 13:44:05 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file RPN.hpp
 * @brief Declaration for the RPN class.
 */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdexcept>
#include <string>

/**
 * @class RPN
 * @brief A simple Reverse Polish Notation expressions evaluator.
 *
 * It parses RPN expressions composed by single digit numbers and arithimetic
 * operators. Brackets are not supported.
 */
class RPN {
public:
  /**
   * @brief Default constructor for the RPN class.
   *
   * Constructs a RPN object with an empty expression.
   */
  RPN(void);

  /**
   * @brief Parametrized constructor for the RPN class.
   *
   * Constructs a RPN object with the specified expression.
   *
   * @param expr The RPN expression to be used.
   * @throw std::runtime_error If there is an invalid token.
   */
  RPN(const std::string &expr);

  /**
   * @brief Copy constructor for the RPN class.
   *
   * Constructs a RPN object by copying the contents from another RPN object.
   *
   * @param other The RPN object to be copied.
   */
  RPN(const RPN &other);

  /**
   * @brief Destructor for the RPN class.
   */
  ~RPN(void);

  /**
   * @brief Assignment operator for the RPN class.
   *
   * @param other The RPN object to be assigned.
   * @return A reference to the RPN object.
   */
  RPN &operator=(const RPN &other);

  /**
   * @brief Evaluates the expression and returns its result.
   *
   * @return The result of the expression.
   * @throw std::runtime_error If the evaluation fails.
   */
  int result(void) const;

private:
  std::stack<char> _tokens; /**< The RPN tokens. */

  /**
   * @brief Performs an arithimetic operation between two numbers.
   *
   * @param op The operation to perform (e.g. '+', '-', '*' or '/').
   * @param firstOperand The first operand of the operation.
   * @param secondOperand The second operand of the operation.
   * @return The result of the operation.
   * @throw std::runtime_error If the operation is invalid, or if there is a
   * division by 0.
   */
  int doOp(char op, int firstOperand, int secondOperand) const;

  /**
   * @brief Template auxiliary function for popping the top value of a
   * std::stack.
   *
   * @tparam T The type of the elements of the stack.
   * @param stack The stack to pop from.
   * @return The popped element from the stack.
   * @throw std::runtime_error If the stack is empty.
   */
  template <typename T> static T popStack(std::stack<T> &stack) {
    T value;

    if (stack.empty()) {
      throw std::runtime_error("Unexpected end of stack");
    }
    value = stack.top();
    stack.pop();
    return (value);
  }
};

#endif // !RPN_HPP
