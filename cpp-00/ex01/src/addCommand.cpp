/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addCommand.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:30:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/26 14:42:24 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.hpp"
#include "prompt.hpp"

void addCommand(PhoneBook &book) {
  Contact ctt;

  std::cout << "Add a contact" << std::endl;

  ctt.setFirstName(prompt("First name: "));
  ctt.setLastName(prompt("Last name: "));
  ctt.setNickname(prompt("Nickname: "));
  ctt.setPhoneNumber(prompt("Phone number: "));
  ctt.setDarkestSecret(prompt("Darkest secret: "));

  book.addContact(ctt);
}
