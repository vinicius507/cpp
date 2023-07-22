/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:07:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 14:49:59 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Form.hpp
 * @brief Declaration for the Form class.
 */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

/**
 * @class Form
 * @brief Represents a bureaucratic form.
 */
class Form {
public:
  /**
   * @brief Default constructor for the Form class.
   *
   * Constructs an unnamed Form object with the default required grades of 150.
   */
  Form(void);

  /**
   * @brief Parametrized constructor for the Form class.
   *
   * Constructs a Form object with the specified name and the default required
   * grades of 150.
   *
   * @param _name The name of the Form object.
   */
  explicit Form(const std::string &_name);

  /**
   * @brief Copy constructor for the Form object.
   *
   * Constructs a Form object by copying the contents from another Form object.
   *
   * @param other The Form object to be copied.
   */
  Form(const Form &other);

  /**
   * @brief Destructor for the Form class.
   */
  ~Form(void);

  /**
   * @brief Assignment operator for the Form class.
   *
   * @param other The Form object to be asssigned.
   * @return A reference to the Form object.
   */
  Form &operator=(const Form &other);

  /**
   * @brief Retrieves the name of the Form object.
   */
  const std::string &getName(void) const;

  /**
   * @brief Retrieves the required signing grade for the Form object.
   *
   * @return The grade required for a Bureaucrat to sign the Form.
   */
  int getRequiredSigningGrade(void) const;

  /**
   * @brief Retrieves the required execution grade for the Form object.
   *
   * @return The grade required for a Bureaucrat to execute the Form.
   */
  int getRequiredExecutionGrade(void) const;

  /**
   * @brief Sets the name of the Form object.
   *
   * @param _name The new name for the Form object.
   */
  void setName(const std::string &_name);

  /**
   * @brief Sets the required grade to sign the Form object.
   *
   * @param _grade The new required signing grade for the Form object.
   * @throws Form::GradeTooHighException If the grade value is too high.
   * @throws Form::GradeTooLowException If the grade value is too low.
   */
  void setRequiredSigningGrade(int _grade);

  /**
   * @brief Sets the required grade to execute the Form object.
   *
   * @param _grade The new required execution grade for the Form object.
   * @throws Form::GradeTooHighException If the grade value is too high.
   * @throws Form::GradeTooLowException If the grade value is too low.
   */
  void setRequiredExecutionGrade(int _grade);

  /**
   * @brief The Form object is signed if the Bureaucrat object has a grade
   * equals or higher than the required signing grade.
   *
   * @param b The Bureaucrat who will sign the Form.
   * @throws Form::GradeTooLowException If the Bureaucrat object grade is
   * lower than the required signing grade of the Form object.
   */
  void beSigned(const Bureaucrat &b);

  /**
   * @brief Checks whether the Form object is signed.
   *
   * @return `true` if the Form object is signed, otherwise `false`.
   */
  bool isSigned(void) const;

  /**
   * @class GradeTooHighException
   * @brief Exception for grade values higher than 1 (e.g. 0).
   */
  class GradeTooHighException : public std::exception {
  public:
    /**
     * @brief Get the description of the exception.
     *
     * @return A string describing the exception.
     */
    const char *what(void) const throw();
  };

  /**
   * @class GradeTooLowException
   * @brief Exception for grade values lower than 1 (e.g. 0).
   */
  class GradeTooLowException : public std::exception {
  public:
    /**
     * @brief Get the description of the exception.
     *
     * @return A string describing the exception.
     */
    const char *what(void) const throw();
  };

private:
  const std::string name;         /**< The name of the Form object. */
  bool signedStatus;              /**< Whether the Form is signed. */
  const int requiredSigningGrade; /**< The grade required to sign the form. */
  const int
      requiredExecutionGrade; /**< The grade required to execute the form. */
};

/**
 * @brief Insertion operator overload for the Form class.
 *
 * @param out The target output stream.
 * @param f The Form object to be inserted into the output stream.
 */
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif // !FORM_HPP
