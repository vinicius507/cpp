/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:18:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/30 15:45:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

/**
 * @file FragTrap.hpp
 * @brief Declaration for the FragTrap class.
 */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  /**
   * @brief Default constructor for the FragTrap class.
   *
   * Constructs a FragTrap object with the default name "FR4G-TP".
   */
  FragTrap(void);

  /**
   * @brief Parametrized constructor for the FragTrap class.
   *
   * Constructs a FragTrap objbet with the specified name.
   *
   * @param name The name for the FragTrap object.
   */
  explicit FragTrap(const std::string name);

  /**
   * @brief Copy constructor for the FragTrap class.
   *
   * Constructs a FragTrap object by copying the contents from another FragTrap
   * object.
   *
   * @param other The FragTrap object to be copied.
   */
  FragTrap(const FragTrap &other);

  /**
   * @brief Destructor for the ClapTrap class.
   */
  ~FragTrap(void);

  /**
   * @brief Assignment operator for the FragTrap class.
   *
   * @param other The FragTrap object to be assigned.
   * @return A reference to the FragTrap object.
   */
  FragTrap &operator=(const FragTrap &other);

  /**
   * @brief The FragTrap requests to high five others.
   */
  void highFivesGuys(void);
};

#endif // !FRAGTRAP_HPP
