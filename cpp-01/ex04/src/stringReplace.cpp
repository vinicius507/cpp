/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringReplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:30:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/27 14:05:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringReplace.hpp"
#include <sstream>

std::string stringReplace(const std::string &str, const std::string &searchStr,
                          const std::string &replaceStr, int count) {
  size_t start;
  size_t search;
  int substitutions;
  std::stringstream buf;

  if (str.empty() || searchStr.empty()) {
    return (str);
  }
  start = 0;
  search = str.find(searchStr);
  substitutions = 0;
  while (search != std::string::npos) {
    if (count != ALL_MATCHES && substitutions++ == count) {
      break;
    }
    buf << str.substr(start, search - start) << replaceStr;
    start = search + searchStr.length();
    search = str.find(searchStr, start);
  }
  buf << str.substr(start);
  return (buf.str());
}
