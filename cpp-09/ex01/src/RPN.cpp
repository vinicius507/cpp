/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:59:22 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/19 14:51:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

RPN::RPN(void) {}

RPN::RPN(const std::string &expr) {
  std::string::const_reverse_iterator it;
  std::string allowedChars("0123456789+-*/");

  for (it = expr.crbegin(); it != expr.crend(); it++) {
    if (*it == ' ') {
      continue;
    }
    if (allowedChars.find(*it) == std::string::npos) {
      throw "Err";
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
  std::stack<char> stackCopy(this->_tokens);

  while (!stackCopy.empty()) {
    char c = popStack(stackCopy);

    if (std::isdigit(c)) {
      aux.push(c - '0');
      continue;
    }

    if (aux.size() < 2) {
      throw std::runtime_error(std::string("Unexpected token: ") + c);
    }

    int secondOperand = popStack(aux);
    int firstOperand = popStack(aux);

    switch (c) {
    case '+':
      aux.push(firstOperand + secondOperand);
      break;
    case '-':
      aux.push(firstOperand - secondOperand);
      break;
    case '*':
      aux.push(firstOperand * secondOperand);
      break;
    case '/':
      if (secondOperand == 0) {
        throw std::logic_error("Division by 0");
      }
      aux.push(firstOperand / secondOperand);
      break;
    default:
      throw std::runtime_error(std::string("Unexpected token: ") + c);
      break;
    }
  }
  return (aux.top());
}
