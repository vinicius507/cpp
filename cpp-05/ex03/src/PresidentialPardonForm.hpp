/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:39:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/09 14:31:58 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file PresidentialPardonForm.hpp
 * @brief Declaration for the PresidentialPardonForm class.
 */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  /**
   * @brief Default constructor for the PresidentialPardonForm class.
   *
   * Constructs a PresidentialPardonForm for an unnamed target and default
   * required grades of 25, for signing, and 5, for execution.
   */
  PresidentialPardonForm(void);

  /**
   * @brief Parametrized constructor for the PresidentialPardonForm class.
   *
   * Constructs a PresidentialPardonForm object for the specified target.
   *
   * @param _target The target of the PresidentialPardonForm object.
   */
  PresidentialPardonForm(const std::string &_target);

  /**
   * @brief Copy constructor for the PresidentialPardonForm class.
   *
   * Constructs a PresidentialPardonForm class by copying the contents from
   * another PresidentialPardonForm object.
   *
   * @param other The PresidentialPardonForm object to be copied.
   */
  PresidentialPardonForm(const PresidentialPardonForm &other);

  /**
   * @brief Destructor for the PresidentialPardonForm class.
   */
  ~PresidentialPardonForm(void);

  /**
   * @brief Assignment operator for the PresidentialPardonForm class.
   *
   * @param other The PresidentialPardonForm object to be assigned.
   * @return A reference to the PresidentialPardonForm object.
   */
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  /**
   * @brief Retrieves the target of the PresidentialPardonForm object.
   */
  const std::string &getTarget(void) const;

  /**
   * @brief Sets the target of the PresidentialPardonForm object.
   *
   * @param _target The target of the PresidentialPardonForm object.
   */
  void setTarget(const std::string &_target);

  /**
   * @brief The PresidentialPardonForm object is executed by a Bureaucrat
   * object.
   *
   * @param executor The Bureaucrat object who will execute the
   * PresidentialPardonForm object.
   * @throws AForm::FormIsUnsigned If the form is unsigned.
   * @throws AForm::GradeTooLowException If the executor's grade is too low.
   */
  virtual void execute(const Bureaucrat &executor) const;

private:
  const std::string
      target; /**< The target of the PresidentialPardonForm object. */
};

#endif // !PRESIDENTIALPARDONFORM_HPP
