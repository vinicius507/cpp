/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:07:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/07/18 16:41:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file AForm.hpp
 * @brief Declaration for the AForm class.
 */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

/**
 * @class AForm
 * @brief Represents a bureaucratic form.
 */
class AForm {
public:
  /**
   * @brief Default constructor for the AForm class.
   *
   * Constructs an unnamed AForm object with the default required grades of 150.
   */
  AForm(void);

  /**
   * @brief Parametrized constructor for the AForm class.
   *
   * Constructs a AForm object with the specified name and the default required
   * grades of 150.
   *
   * @param name The name of the AForm object.
   */
  explicit AForm(const std::string &name);

  /**
   * @brief Copy constructor for the AForm object.
   *
   * Constructs a AForm object by copying the contents from another AForm
   * object.
   *
   * @param other The AForm object to be copied.
   */
  AForm(const AForm &other);

  /**
   * @brief Destructor for the AForm class.
   */
  virtual ~AForm(void);

  /**
   * @brief Assignment operator for the AForm class.
   *
   * @param other The AForm object to be asssigned.
   * @return A reference to the AForm object.
   */
  AForm &operator=(const AForm &other);

  /**
   * @brief Retrieves the name of the AForm object.
   */
  const std::string &getName(void) const;

  /**
   * @brief Retrieves the required signing grade for the AForm object.
   *
   * @return The grade required for a Bureaucrat to sign the AForm.
   */
  int getRequiredSigningGrade(void) const;

  /**
   * @brief Retrieves the required execution grade for the AForm object.
   *
   * @return The grade required for a Bureaucrat to execute the AForm.
   */
  int getRequiredExecutionGrade(void) const;

  /**
   * @brief Sets the name of the AForm object.
   *
   * @param _name The new name for the AForm object.
   */
  void setName(const std::string &_name);

  /**
   * @brief Sets the required grade to sign the AForm object.
   *
   * @param grade The new required signing grade for the AForm object.
   * @throws AForm::GradeTooHighException If the grade value is too high.
   * @throws AForm::GradeTooLowException If the grade value is too low.
   */
  void setRequiredSigningGrade(int grade);

  /**
   * @brief Sets the required grade to execute the AForm object.
   *
   * @param grade The new required execution grade for the AForm object.
   * @throws AForm::GradeTooHighException If the grade value is too high.
   * @throws AForm::GradeTooLowException If the grade value is too low.
   */
  void setRequiredExecutionGrade(int grade);

  /**
   * @brief The AForm object is signed if the Bureaucrat object has a grade
   * equals or higher than the required signing grade.
   *
   * @param b The Bureaucrat who will sign the AForm.
   * @throws AForm::GradeTooLowException If the Bureaucrat object grade is
   * lower than the required signing grade of the AForm object.
   */
  void beSigned(const Bureaucrat &b);

  /**
   * @brief Checks whether the AForm object is signed.
   *
   * @return `true` if the AForm object is signed, otherwise `false`.
   */
  bool isSigned(void) const;

  /**
   * @brief The AForm object is executed by a Bureaucrat object.
   *
   * @param executor The Bureaucrat object who will execute the AForm object.
   */
  virtual void execute(const Bureaucrat &executor) const = 0;

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

  /**
   * @class FormIsUnsigned
   * @brief Exception thrown when a Bureaucrat tries to execute the AForm object
   * and it is unsigned.
   */
  class FormIsUnsigned : public std::exception {
  public:
    /**
     * @brief Get the description of the exception.
     *
     * @return A string describing the exception.
     */
    const char *what(void) const throw();
  };

private:
  const std::string name;         /**< The name of the AForm object. */
  bool signedStatus;              /**< Whether the AForm is signed. */
  const int requiredSigningGrade; /**< The grade required to sign the form. */
  const int
      requiredExecutionGrade; /**< The grade required to execute the form. */
};

/**
 * @brief Insertion operator overload for the AForm class.
 *
 * @param out The target output stream.
 * @param f The AForm object to be inserted into the output stream.
 */
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif // !FORM_HPP
