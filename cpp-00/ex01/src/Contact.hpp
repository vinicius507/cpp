/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/26 14:38:24 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Contact.hpp
 * @brief Declaration of the Contact class.
 */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

/**
 * @brief Represents a contact with first name, last name, nickname, phone
 * number, and darkest secret.
 */
class Contact {
public:
  /**
   * @brief Default constructor for Contact class.
   */
  Contact(void);

  /**
   * @brief Destructor for Contact class.
   */
  ~Contact(void);

  /**
   * @brief Setter for the first name of the contact.
   * @param first_name The new first name for the contact.
   */
  void setFirstName(std::string first_name);

  /**
   * @brief Setter for the last name of the contact.
   * @param last_name The new last name for the contact.
   */
  void setLastName(std::string last_name);

  /**
   * @brief Setter for the nickname of the contact.
   * @param nickname The new nickname for the contact.
   */
  void setNickname(std::string nickname);

  /**
   * @brief Setter for the phone number of the contact.
   * @param phone_number The new phone number for the contact.
   */
  void setPhoneNumber(std::string phone_number);

  /**
   * @brief Setter for the darkest secret of the contact.
   * @param darkest_secret The new darkest secret for the contact.
   */
  void setDarkestSecret(std::string darkest_secret);

  /**
   * @brief Getter for the first name of the contact.
   * @return The first name of the contact.
   */
  std::string getFirstName(void);

  /**
   * @brief Getter for the last name of the contact.
   * @return The last name of the contact.
   */
  std::string getLastName(void);

  /**
   * @brief Getter for the nickname of the contact.
   * @return The nickname of the contact.
   */
  std::string getNickname(void);

  /**
   * @brief Getter for the phone number of the contact.
   * @return The phone number of the contact.
   */
  std::string getPhoneNumber(void);

  /**
   * @brief Getter for the darkest secret of the contact.
   * @return The darkest secret of the contact.
   */
  std::string getDarkestSecret(void);

private:
  std::string firstName;     /**< The first name of the contact. */
  std::string lastName;      /**< The last name of the contact. */
  std::string nickname;      /**< The nickname of the contact. */
  std::string phoneNumber;   /**< The phone number of the contact. */
  std::string darkestSecret; /**< The darkest secret of the contact. */
};

#endif // !CONTACT_H
