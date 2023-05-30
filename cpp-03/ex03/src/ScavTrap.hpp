/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:00:47 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/30 16:33:13 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ScavTrap.hpp
 * @brief Declaration for the ScavTrap class.
 */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  /**
   * @brief Default constructor for the ScavTrap class.
   *
   * Constructs a ScavTrap object with the default name "5C4V-TP".
   */
  ScavTrap(void);

  /**
   * @brief Parametrized constructor for the ScavTrap class.
   *
   * Constructs a ScavTrap object with the specified name.
   *
   * @param name The name for the ScavTrap object.
   */
  explicit ScavTrap(const std::string name);

  /**
   * @brief Copy constructor for the ScavTrap class.
   *
   * Constructs a ScavTrap object by copying the contents of an already existing
   * ScavTrap object.
   *
   * @param other The ScavTrap object to be copied.
   */
  ScavTrap(const ScavTrap &other);

  /**
   * @brief Destructor for the ScavTrap class.
   */
  ~ScavTrap(void);

  /**
   * @brief Assignment operator for the ScavTrap class.
   *
   * @param other The ScavTrap object to be assigned.
   * @return A reference to the ScavTrap object.
   */
  ScavTrap &operator=(const ScavTrap &other);

  /**
   * @brief The ScavTrap object attacks a target.
   *
   * @param target The target of the attack.
   */
  void attack(const std::string target);

  /**
   * @brief The ScavTrap object enters the Gate Keeper mode.
   */
  void guardGate(void);
};

#endif
