/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:26:39 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/09 14:37:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file RobotomyRequestForm.hpp
 * @brief Declaration for the RobotomyRequestForm class.
 */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/**
 * @class RobotomyRequestForm
 * @brief Represents a Robotomy Request Form.
 */
class RobotomyRequestForm : public AForm {
public:
  /**
   * @brief Default constructor for the RobotomyRequestForm class.
   *
   * Constructs a RobotomyRequestForm template, with required grades of 72, for
   * signing, and 45 for execution.
   */
  RobotomyRequestForm(void);

  /**
   * @brief Parametrized constructor for the RobotomyRequestForm class.
   *
   * Constructs a RobotomyRequestForm with the specified target.
   *
   * @param target The target of the RobotomyRequestForm object.
   */
  RobotomyRequestForm(const std::string &target);

  /**
   * @brief Copy constructor for the RobotomyRequestForm class.
   *
   * Constructs a RobotomyRequestForm object by copying the contents from
   * another RobotomyRequestForm object.
   *
   * @param other The RobotomyRequestForm object to be copied.
   */
  RobotomyRequestForm(const RobotomyRequestForm &other);

  /**
   * @brief Destructor for the RobotomyRequestForm class.
   */
  ~RobotomyRequestForm(void);

  /**
   * @brief Assignment operator for the RobotomyRequestForm class.
   *
   * @param other The RobotomyRequestForm object to be assigned.
   * @return A reference to the RobotomyRequestForm.
   */
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  /**
   * @brief Retrieves the target of the RobotomyRequestForm object.
   */
  const std::string &getTarget(void) const;

  /**
   * @brief Sets the target of the RobotomyRequestForm object.
   *
   * @param target The target of the RobotomyRequestForm object.
   */
  void setTarget(const std::string &_target);

  /**
   * @brief The RobotomyRequestForm object is executed by a Bureaucrat object.
   *
   * @param executor The Bureaucrat object who will execute the
   * RobotomyRequestForm object.
   * @throws AForm::FormIsUnsigned If the form is unsigned.
   * @throws AForm::GradeTooLowException If the executor's grade is too low.
   */
  void execute(const Bureaucrat &executor) const;

private:
  const std::string
      target; /**< The target of the RobotomyRequestForm object. */
};

#endif // !ROBOTOMYREQUESTFORM_HPP
