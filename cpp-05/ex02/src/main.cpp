/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:24:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 15:39:03 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>
#include <iostream>

#define TEST(TEST_CASE)                                                        \
  do {                                                                         \
    std::cout << "Test: " << #TEST_CASE << std::endl;                          \
    TEST_CASE();                                                               \
    std::cout << std::setw(32) << std::setfill('-') << "" << std::endl;        \
  } while (0)

#define EXPECT_TRUE(EXPR)                                                      \
  do {                                                                         \
    std::cout << (EXPR ? "[OK]" : "[KO]") << " " #EXPR " == true"              \
              << std::endl;                                                    \
  } while (0)

#define EXPECT_FALSE(EXPR)                                                     \
  do {                                                                         \
    std::cout << (!(EXPR) ? "[OK]" : "[KO]") << " " #EXPR " == false"          \
              << std::endl;                                                    \
  } while (0)

#define EXPECT_EXCEPTION(EXPR, EXC)                                            \
  do {                                                                         \
    try {                                                                      \
      EXPR;                                                                    \
      std::cout << "[KO] " #EXPR " did not throw the exception " #EXC          \
                << std::endl;                                                  \
    } catch (std::exception & e) {                                             \
      if (e.what() == EXC().what()) {                                          \
        std::cout << "[OK] " #EXPR " did throw " #EXC << std::endl;            \
      } else {                                                                 \
        std::cout << "[KO] " #EXPR " did not throw " #EXC << std::endl;        \
      }                                                                        \
    }                                                                          \
  } while (0)

#define EXPECT(EXPR, VALUE)                                                    \
  do {                                                                         \
    std::cout << ((EXPR) == VALUE ? "[OK]" : "[KO]")                           \
              << " " #EXPR " == " #VALUE << std::endl;                         \
  } while (0)

int main(void) { return (0); }
