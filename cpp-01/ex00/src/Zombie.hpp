/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 16:09:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Zombie.hpp
 * @brief Declaration of the Zombie class.
 */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

/**
 * @class Zombie
 * @brief Represents a Zombie with a name. 🧟
 */
class Zombie {
public:
  /**
   * @brief Default constructor for the Zombie class.
   */
  Zombie(void);

  /**
   * @brief Create a named Zombie.
   *
   * @param name The name of the Zombie.
   */
  Zombie(std::string name);

  /**
   * @brief Copy constructor for the Zombie class.
   *
   * @param other A Zombie instance.
   */
  Zombie(const Zombie &other);

  /**
   * @brief Destructor for the Zombie class.
   */
  ~Zombie(void);

  /**
   * @brief The zombie announces itself to the world! 🧟
   */
  void announce(void);

private:
  std::string _name; /**< The name of the zombie. */
};

#endif // !ZOMBIE_HPP
