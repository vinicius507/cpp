/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:59:22 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/20 14:54:58 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const std::string &expr) {
  std::string::size_type idx;
  std::string::const_reverse_iterator it;
  std::string allowedChars("0123456789+-*/");

  idx = expr.find_first_not_of(allowedChars + ' ');
  if (idx != std::string::npos) {
    throw std::runtime_error(std::string("Invalid token: '") + expr[idx] + '\'');
  }
  if (expr.find_first_of(allowedChars) == std::string::npos) {
    throw std::runtime_error("Empty expression");
  }
  for (it = expr.rbegin(); it != expr.rend(); ++it) {
    if (std::isspace(*it)) {
      continue;
    }
    this->_tokens.push(*it);
  }
}

RPN::RPN(const RPN &other) : _tokens(other._tokens) {}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    this->_tokens = std::stack<char>(other._tokens);
  }
  return (*this);
}

int RPN::result(void) const {
  std::stack<int> aux;
  std::string ops("+-*/");
  std::stack<char> stackCopy;

  if (this->_tokens.size() == 1) {
    throw std::runtime_error("Unterminated expression");
  }
  stackCopy = std::stack<char>(this->_tokens);
  while (!stackCopy.empty()) {
    char c = popStack(stackCopy);
    if (std::isdigit(c)) {
      aux.push(c - '0');
      continue;
    }
    if (aux.size() < 2) {
      throw std::runtime_error("Insufficient operands");
    }
    int secondOperand = popStack(aux);
    int firstOperand = popStack(aux);
    aux.push(this->doOp(c, firstOperand, secondOperand));
  }
  if (aux.size() > 1) {
    throw std::runtime_error("Unterminated expression");
  }
  return (aux.top());
}

int RPN::doOp(char op, int firstOperand, int secondOperand) const {
  switch (op) {
  case '+':
    return firstOperand + secondOperand;
    break;
  case '-':
    return (firstOperand - secondOperand);
    break;
  case '*':
    return (firstOperand * secondOperand);
    break;
  case '/':
    if (secondOperand == 0) {
      throw std::runtime_error("Division by zero");
    }
    return (firstOperand / secondOperand);
    break;
  default:
    throw std::runtime_error(std::string("Unexpected token: ") + op);
    break;
  }
}
