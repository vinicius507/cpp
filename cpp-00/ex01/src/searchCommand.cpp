/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchCommand.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:34:20 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/22 15:29:05 by vgoncalv         ###   ########.fr       */
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

static std::string phonebookTable(PhoneBook &book) {
  Contact ctt;
  std::stringstream tbl;

  tbl << tableBorder() << tableRow("Id", "First name", "Last name", "Nickname")
      << tableBorder();

  for (int i = 0; i < book.get_num_contacts(); i++) {
    ctt = book.get_contact(i);

    tbl << tableRow(std::to_string(i + 1), ctt.get_first_name(),
                    ctt.get_last_name(), ctt.get_nickname());
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

    if (index > 0 && index <= book.get_num_contacts()) {
      return (index - 1);
    }

    std::cerr << "Error: expected a positive integer smaller than"
              << book.get_num_contacts() + 1 << std::endl;
  }
}

static void displayContactInfo(Contact &ctt) {
  std::cout << "First name: " << ctt.get_first_name() << std::endl
            << "Last name: " << ctt.get_last_name() << std::endl
            << "Nickname: " << ctt.get_nickname() << std::endl
            << "Phone number: " << ctt.get_phone_number() << std::endl
            << "Darkest secret: " << ctt.get_darkest_secret() << std::endl;
}

void searchCommand(PhoneBook &book) {
  int index;
  Contact ctt;

  if (book.get_num_contacts() == 0) {
    std::cout << "There are 0 contacts in the phonebook." << std::endl;
    return;
  }

  std::cout << phonebookTable(book);
  index = getContactIndex(book);
  ctt = book.get_contact(index);
  displayContactInfo(ctt);
}
