/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:28:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/22 15:20:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "commands.hpp"
#include "prompt.hpp"

/**
 * @brief Returns the desired command handler function.
 *
 * @param cmd The command string.
 * @return A pointer to the handler of `cmd`, if it exists. Otherwise, it is
 * NULL.
 */
static t_cmd_handler getCommandHandler(std::string cmd) {
  if (cmd == "ADD")
    return (addCommand);
  if (cmd == "SEARCH")
    return (searchCommand);
  return (NULL);
}

int main(void) {
  PhoneBook book;
  std::string cmd;
  t_cmd_handler handler;

  std::cout << "Welcome to the Phonebook CLI tool!" << std::endl
            << "You can use the following commands:" << std::endl
            << "  ADD       Adds a contact to the Phonebook" << std::endl
            << "  SEARCH    Views information about a contact" << std::endl
            << "  EXIT      Exits the application" << std::endl;

  do {
    cmd = prompt("\nphonebook# ");

    if (cmd == "EXIT")
      break;

    handler = getCommandHandler(cmd);

    if (handler == NULL) {
      std::cerr << "Unknown command: " << cmd << std::endl;
      continue;
    }

    handler(book);
  } while (1);
  return 0;
}
