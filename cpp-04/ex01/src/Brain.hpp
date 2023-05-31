/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:47:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/31 14:58:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

/**
 * @class Brain
 * @brief Represents the Brain of a living being.
 */
class Brain {
public:
  /**
   * @brief Default constructor for the Brain class.
   *
   * Constructs a Brain object without any ideas.
   */
  Brain(void);

  /**
   * @brief Copy constructor for the Brain class.
   *
   * Constructs a Brain object by copying the ideas of another Brain object.
   *
   * @param other The Brain object to be copied.
   */
  Brain(const Brain &other);

  /**
   * @brief Destructor for the Brain class.
   */
  ~Brain(void);

  /**
   * @brief Assignment operator for the Brain class.
   *
   * @param other The Brain object to be assigned.
   * @return A reference to the Brain object.
   */
  Brain &operator=(const Brain &other);

  /**
   * @brief Retrieves an idea from the Brain object.
   *
   * @param index The index of the idea.
   * @return The idea, if it exists, otherwise an empty std::string.
   */
  std::string getIdea(const unsigned int index) const;

  /**
   * @brief The Brain object thinks a new idea.
   *
   * @param idea The new idea thought by the Brain object.
   */
  void newIdea(std::string idea);

private:
  std::string ideas[100];
};

#endif // !BRAIN_HPP
