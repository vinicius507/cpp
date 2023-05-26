/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/26 14:38:58 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){};

Contact::~Contact(void){};

void Contact::setFirstName(std::string firstName) {
  this->firstName = firstName;
};

void Contact::setLastName(std::string lastName) { this->lastName = lastName; };

void Contact::setNickname(std::string nickname) { this->nickname = nickname; };

void Contact::setPhoneNumber(std::string phoneNumber) {
  this->phoneNumber = phoneNumber;
};

void Contact::setDarkestSecret(std::string darkestSecret) {
  this->darkestSecret = darkestSecret;
};

std::string Contact::getFirstName(void) { return this->firstName; };

std::string Contact::getLastName(void) { return this->lastName; };

std::string Contact::getNickname(void) { return this->nickname; };

std::string Contact::getPhoneNumber(void) { return this->phoneNumber; };

std::string Contact::getDarkestSecret(void) { return this->darkestSecret; };
