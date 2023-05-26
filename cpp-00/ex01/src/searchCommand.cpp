/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchCommand.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:34:20 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/26 14:42:13 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "prompt.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

static std::string tableBorder(void) {
  std::stringstream border;

  for (int i = 0; i < 4; i++) {
    border << "+" << std::setw(11) << std::setfill('-');
  }
  border << "+" << std::endl;

  return (border.str());
}

static std::string tableCell(std::string content) {
  std::stringstream cell;

  cell << "|" << std::setw(10) << std::setfill(' ');

  if (content.length() > 10) {
    cell << content.substr(0, 9) + ".";
  } else {
    cell << content;
  }

  return (cell.str());
}

static std::string tableRow(std::string id, std::string first_name,
                            std::string last_name, std::string nickname) {
  std::stringstream row;

  row << tableCell(id) << tableCell(first_name) << tableCell(last_name)
      << tableCell(nickname) << "|" << std::endl;

  return (row.str());
}

static std::string idToString(int id) {
  std::stringstream ss;

  ss << id;
  return (ss.str());
}

static std::string phonebookTable(PhoneBook &book) {
  Contact ctt;
  std::stringstream tbl;

  tbl << tableBorder() << tableRow("Id", "First name", "Last name", "Nickname")
      << tableBorder();

  for (int i = 0; i < book.getNumContacts(); i++) {
    ctt = book.getContact(i);

    tbl << tableRow(idToString(i + 1), ctt.getFirstName(), ctt.getLastName(),
                    ctt.getNickname());
  }

  tbl << tableBorder();

  return (tbl.str());
}

static int getContactIndex(PhoneBook &book) {
  int index;
  std::stringstream ss;

  while (1) {
    ss.str(std::string());
    ss.clear();
    ss << prompt("Choose a contact by its index to view its information: ");
    ss >> index;

    if (index > 0 && index <= book.getNumContacts()) {
      return (index - 1);
    }

    std::cerr << "Error: expected a positive integer smaller than"
              << book.getNumContacts() + 1 << std::endl;
  }
}

static void displayContactInfo(Contact &ctt) {
  std::cout << "First name: " << ctt.getFirstName() << std::endl
            << "Last name: " << ctt.getLastName() << std::endl
            << "Nickname: " << ctt.getNickname() << std::endl
            << "Phone number: " << ctt.getPhoneNumber() << std::endl
            << "Darkest secret: " << ctt.getDarkestSecret() << std::endl;
}

void searchCommand(PhoneBook &book) {
  int index;
  Contact ctt;

  if (book.getNumContacts() == 0) {
    std::cout << "There are 0 contacts in the phonebook." << std::endl;
    return;
  }

  std::cout << phonebookTable(book);
  index = getContactIndex(book);
  ctt = book.getContact(index);
  displayContactInfo(ctt);
}
