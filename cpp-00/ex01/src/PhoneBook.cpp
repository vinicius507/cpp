/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:11:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/26 14:41:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void) { this->numContacts = 0; };

PhoneBook::~PhoneBook(void){};

int PhoneBook::getNumContacts(void) { return this->numContacts; }

Contact &PhoneBook::getContact(int index) {
  if (index < 0 || index >= this->numContacts) {
    return ((Contact &)EMPTY_CONTACT);
  }
  return (this->contacts[index]);
};

void PhoneBook::addContact(Contact contact) {
  static int i;

  if (this->numContacts < 8) {
    this->numContacts++;
  }

  this->contacts[i] = contact;
  i = (i + 1) % 8;
}
