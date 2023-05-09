/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:55:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 20:02:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
  std::string string = "HI THIS IS BRAIN";
  std::string *stringPTR = &string;
  std::string &stringREF = string;

  std::cout << "Addresses:" << std::endl
            << "string: " << &string << std::endl
            << "stringPTR: " << stringPTR << std::endl
            << "stringREF: " << &stringREF << std::endl
            << std::endl
            << "Values:" << std::endl
            << "string: " << string << std::endl
            << "stringPTR: " << *stringPTR << std::endl
            << "stringREF: " << stringREF << std::endl
            << std::endl;
  return (0);
}
