/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:56:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/22 16:01:33 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
public:
  /**
   * @brief Default constructor for the Harl class.
   */
  Harl(void);

  /**
   * @brief Default destructor for the Harl class.
   */
  ~Harl(void);

  /**
   * @brief Harl complains starting from `level`.
   *
   * @param level The level at which Harl starts complaining.
   */
  void complain(std::string level);

private:
  /**
   * @brief Harl sends a debug message.
   */
  void debug(void);

  /**
   * @brief Harl sends an info message.
   */
  void info(void);

  /**
   * @brief Harl sends a warning message.
   */
  void warning(void);

  /**
   * @brief Harl sends an error message.
   */
  void error(void);
};

#endif // !HARL_HPP
