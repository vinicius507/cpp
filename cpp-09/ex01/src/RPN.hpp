/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:49:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/19 14:31:05 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdexcept>
#include <string>

class RPN {
public:
  RPN(void);

  RPN(const std::string &expr);

  RPN(const RPN &other);

  ~RPN(void);

  RPN &operator=(const RPN &other);

  int result(void) const;

private:
  std::stack<char> _stack;

  template <typename T> static char popStack(std::stack<T> &stack) {
    char c;

    if (stack.empty()) {
      throw std::runtime_error("Unexpected end of stack");
    }
    c = stack.top();
    stack.pop();
    return (c);
  }
};

#endif // !RPN_HPP
