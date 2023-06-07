/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:35:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 18:47:57 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Bureaucrat.hpp
 * @brief Declaration for the Bureaucrat class.
 */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

/**
 * @class Bureaucrat
 * @brief Represents a Bureaucrat.
 */
class Bureaucrat {
public:
  /**
   * @brief Default constructor for the Bureaucrat class.
   *
   * Constructs an unnamed Bureaucrat object with the default grade 150.
   */
  Bureaucrat(void);

  /**
   * @brief Parametrized constructor for the Bureaucrat class.
   *
   * Constructs a Bureaucrat object with the specified name and grade.
   *
   * @param name The name of the Bureaucrat.
   * @param grade The grade of the Bureaucrat.
   */
  explicit Bureaucrat(const std::string &name, int grade);

  /**
   * @brief Copy constructor for the Bureaucrat class.
   *
   * Constructs a Bureaucrat object by copying the contents from another
   * Bureaucrat object.
   *
   * @param other A reference to the Bureaucrat object to be copied.
   */
  Bureaucrat(const Bureaucrat &other);

  /**
   * @brief Destructor for the Bureaucrat class.
   */
  ~Bureaucrat(void);

  /**
   * @brief Assignment operator for the Bureaucrat class.
   *
   * @param other A reference to the Bureaucrat object to be assigned.
   * @return A reference to the Bureaucrat object.
   */
  Bureaucrat &operator=(const Bureaucrat &other);

  /**
   * @brief Retrieves the name of the Bureaucrat object.
   */
  const std::string &getName(void) const;

  /**
   * @brief Retrieves the grade of the Bureaucrat object.
   */
  int getGrade(void) const;

  /**
   * @brief Sets the name of the Bureaucrat object.
   *
   * @param name The name of the Bureaucrat object.
   */
  void setName(const std::string &_name);

  /**
   * @brief Sets the grade of the Bureaucrat object.
   *
   * @param grade The grade of the Bureaucrat object.
   */
  void setGrade(int _grade);

  /**
   * @brief Increments the grade of the Bureaucrat object.
   */
  void incrementGrade(void);

  /**
   * @brief Decrements the grade of the Bureaucrat object.
   */
  void decrementGrade(void);

  class GradeTooHighException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what(void) const throw();
  };

private:
  const std::string name; /**< The name of the Bureaucrat object. */
  int grade; /**< The grade of the Bureaucrat object, with 1 being the
                highest, while 150 is the lowest. */
};

/**
 * @brief Overload for the insertion operator for the Bureaucrat class.
 *
 * @param out The output stream.
 * @param Bureaucrat The Bureaucrat object to be inserted into the ostream.
 */
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif // !BUREAUCRAT_HPP
