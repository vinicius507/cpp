/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:31:38 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/26 15:04:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.hpp"
#include <iostream>

std::string prompt(std::string prefix) {
  std::string ans;

  std::cout << prefix;
  std::getline(std::cin, ans);
  return ans;
}
