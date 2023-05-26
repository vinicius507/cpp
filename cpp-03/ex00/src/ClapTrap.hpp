/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:40:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/25 22:56:47 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

/**
 * @file ClapTrap.hpp
 * @brief Declaration for the ClapTrap class.
 */

#include <string>

/**
 * @class ClapTrap
 * @brief Represents a ClapTrap (I hope it comes from Borderlands).
 *
 * The ClapTrap has Hit Points, Energy Points and Attack Damage.
 */
class ClapTrap {
public:
  /**
   * @brief Default constructor for the ClapTrap class.
   *
   * Constructs a ClapTrap object with the default name CL4P-TP.
   */
  ClapTrap(void);

  /**
   * @brief Parametrized constructor for the ClapTrap class.
   *
   * Constructs a ClapTrap object with the specified name.
   *
   * @param name The name of the ClapTrap.
   */
  explicit ClapTrap(const std::string name);

  /**
   * @brief Copy constructor for the ClapTrap class.
   *
   * Constructs a ClapTrap object by copying the contents of another ClapTrap
   * object.
   *
   * @param other The ClapTrap to be copied.
   */
  ClapTrap(const ClapTrap &other);

  /**
   * @brief Destructor for the ClapTrap class.
   */
  ~ClapTrap(void);

  /**
   * @brief Assignment operator for the ClapTrap class.
   *
   * @param other The ClapTrap object to be assigned.
   * @return A reference to the ClapTrap object.
   */
  ClapTrap &operator=(const ClapTrap &other);

  /**
   * @brief The ClapTrap object attacks a target.
   *
   * @param target The name of the target.
   */
  void attack(const std::string &target);

  /**
   * @brief The ClapTrap takes damage.
   *
   * When the ClapTrap takes damage, its hit points are deducted by the amount
   * specified.
   *
   * @param amount The amount of damage taken by the ClapTrap object.
   */
  void takeDamage(unsigned int amount);

  /**
   * @brief Repairs the ClapTrap.
   *
   * When repaired, the ClapTrap hit points are increased by the amount
   * specified.
   *
   * @param amount The amount of hit points to restore.
   */
  void beRepaired(unsigned int amount);

  /**
   * @brief Retrieves the name of the ClapTrap object.
   *
   * @return The name of the ClapTrap object.
   */
  std::string getName(void) const;

  /**
   * @brief Retrieves the hit points of the ClapTrap object.
   *
   * @return The hit points of the ClapTrap object.
   */
  unsigned int getHitPoints(void) const;

  /**
   * @brief Retrieves the energy points of the ClapTrap object.
   *
   * @return The energy points of the ClapTrap object.
   */
  unsigned int getEnergyPoints(void) const;

  /**
   * @brief Retrieves the attack damage of the ClapTrap object.
   *
   * @return The attack damage of the ClapTrap object.
   */
  unsigned int getAttackDamage(void) const;

  /**
   * @brief Sets the hit points of the ClapTrap object.
   *
   * If the amount of hitPoints exceeds MAX_HP, hit points will be set to
   * MAX_HP.
   *
   * @param hitPoints The new hit points value for the ClapTrap object.
   */
  void setHitPoints(unsigned int hitPoints);

  /**
   * @brief Sets the energy points of the ClapTrap object.
   *
   * @param hitPoints The new energy points value for the ClapTrap object.
   */
  void setEnergyPoints(unsigned int energyPoints);

  /**
   * @brief Sets the attack damage of the ClapTrap object.
   *
   * @param attackDamage The new attack damage value for the ClapTrap object.
   */
  void setAttackDamage(unsigned int attackDamage);

  /**
   * @brief Checks whether the ClapTrap object has energy points.
   *
   * @return `true` if the ClapTrap object has energy points, `false` otherwise.
   */
  bool hasEnergy(void) const;

  /**
   * @brief The ClapTrap object consumes energy to take action.
   *
   * When the ClapTrap object consumes energy, its energy points amount is
   * reduced by 1.
   */
  void consumeEnergy(void);

  /**
   * @brief Checks whether the ClapTrap object is dead.
   *
   * The ClapTrap object dies once its hit points reach 0.
   *
   * @return `true` if the ClapTrap is dead, `false` otherwise.
   */
  bool isDead(void) const;

private:
  const std::string name;    /**< The name of the ClapTrap. */
  unsigned int hitPoints;    /**< The hit points of the Clap Trap. */
  unsigned int energyPoints; /**< The energy points of the Clap Trap. */
  unsigned int attackDamage; /**< The attack damage of the Clap Trap. */

  static const unsigned int
      MAX_HP; /**< The maximum hit points value for the ClapTrap. */
};

#endif // !CLAPTRAP_HPP
