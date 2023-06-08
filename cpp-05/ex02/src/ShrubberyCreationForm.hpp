/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:25:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/08 17:44:15 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ShrubberyCreationForm.hpp
 * @brief Declaration for the ShrubberyCreationForm class.
 */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
  /**
   * @brief Default constructor for the ShrubberyCreationForm class.
   *
   * Constructs a ShrubberyCreationForm for an unnamed target and default
   * required grades of 25, for signing, and 5, for execution.
   */
  ShrubberyCreationForm(void);

  /**
   * @brief Parametrized constructor for the ShrubberyCreationForm class.
   *
   * Constructs a ShrubberyCreationForm object for the specified target.
   *
   * @param target The target of the ShrubberyCreationForm object.
   */
  ShrubberyCreationForm(const std::string &target);

  /**
   * @brief Copy constructor for the ShrubberyCreationForm class.
   *
   * Constructs a ShrubberyCreationForm class by copying the contents from
   * another ShrubberyCreationForm object.
   *
   * @param other The ShrubberyCreationForm object to be copied.
   */
  ShrubberyCreationForm(const ShrubberyCreationForm &other);

  /**
   * @brief Destructor for the ShrubberyCreationForm class.
   */
  ~ShrubberyCreationForm(void);

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  /**
   * @brief Retrieves the target of the ShrubberyCreationForm object.
   */
  const std::string &getTarget(void) const;

  /**
   * @brief Sets the target of the ShrubberyCreationForm object.
   *
   * @param _target The target of the ShrubberyCreationForm object.
   */
  void setTarget(const std::string &_target);

  /**
   * @brief The ShrubberyCreationForm object is executed by a Bureaucrat
   * object.
   *
   * @param executor The Bureaucrat object who will execute the
   * ShrubberyCreationForm object.
   * @throws AForm::FormIsUnsigned If the form is unsigned.
   * @throws AForm::GradeTooLowException If the executor's grade is too low.
   */
  virtual void execute(const Bureaucrat &executor) const;

  /**
   * @class ShrubberyCreationError
   * @brief Exception thrown when the Shrubbery ASCII tree file could not be
   * created.
   */
  class ShrubberyCreationError : public std::exception {
  public:
    /**
     * @brief Get the description of the exception.
     *
     * @return A string describing the exception.
     */
    const char *what() const throw();
  };

private:
  const std::string
      target; /**< The target of the ShrubberyCreationForm object. */
};

#endif // !PRESIDENTIALPARDONFORM_HPP
