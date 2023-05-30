/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:53:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/30 16:39:44 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  /**
   * @brief Default constructor for the DiamondTrap class.
   *
   * Constructs a DiamondTrap object with the default name D14M0ND-TP.
   */
  DiamondTrap(void);

  /**
   * @brief Parametrized constructor for the DiamondTrap class.
   *
   * Constructs a DiamondTrap object with the specified name.
   *
   * @param name The name for the DiamondTrap object.
   */
  explicit DiamondTrap(const std::string name);

  /**
   * @brief Copy constructor for the DiamondTrap class.
   *
   * Constructs a DiamondTrap object by copying the contents of another
   * DiamondTrap object.
   *
   * @param other The DiamondTrap object to be copied.
   */
  DiamondTrap(const DiamondTrap &other);

  /**
   * @brief Destructor for the DiamondTrap class.
   */
  ~DiamondTrap(void);

  /**
   * @brief Assignment operator for the DiamondTrap class.
   *
   * @param other The DiamondTrap object to be assigned.
   * @return A reference to the DiamondTrap object.
   */
  DiamondTrap &operator=(const DiamondTrap &other);

  /**
   * @brief The DiamondTrap attacks a target.
   *
   * @param target The target of the attack.
   */
  void attack(const std::string &target);

  /**
   * @brief The DiamondTrap answers to the philosophical question "Who am I?".
   */
  void whoAmI(void);

  /**
   * @brief Retrieves the name of the DiamondTrap object.
   *
   * @return The name of the DiamondTrap object.
   */
  std::string getName(void) const;

private:
  const std::string name;
};

#endif // !DIAMONDTRAP_HPP
