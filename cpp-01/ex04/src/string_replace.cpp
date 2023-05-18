/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:30:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/17 22:03:27 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_replace.hpp"
#include <sstream>

std::string string_replace(const std::string &str,
                           const std::string &search_str,
                           const std::string &replace_str, int count) {
  size_t start;
  size_t search;
  int substitutions;
  std::stringstream buf;

  if (str.empty() || search_str.empty()) {
    return (str);
  }
  start = 0;
  search = str.find(search_str);
  substitutions = 0;
  while (search != std::string::npos) {
    if (count != ALL_MATCHES && substitutions++ == count) {
      break;
    }
    buf << str.substr(start, search - start) << replace_str;
    start = search + search_str.length();
    search = str.find(search_str, start);
  }
  buf << str.substr(start) << std::endl;
  return (buf.str());
}
