/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:46:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/22 12:50:18 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <sstream>
#include <string>

template <class Seq> std::string seqToString(Seq &seq) {
  std::stringstream ss;
  typename Seq::iterator it;

  for (it = seq.begin(); it != seq.end(); it++) {
    ss << *it;
    if ((it + 1) != seq.end()) {
      ss << " ";
    }
  }
  return (ss.str());
}

#endif // !BENCHMARK_HPP
