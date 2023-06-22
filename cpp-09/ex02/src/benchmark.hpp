/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:46:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/22 14:52:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include "PmergeMe.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>

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

template <class Seq> void benchSort(Seq &seq, const std::string &type) {
  long elapsedTime;
  void (*sortFunc)(Seq &);
  struct timeval begin, end;

  sortFunc = &PmergeMe::sortVec;
  std::cout << "Before: " << seqToString(seq) << std::endl;
  gettimeofday(&begin, NULL);
  sortFunc(seq);
  gettimeofday(&end, NULL);
  std::cout << "After: " << seqToString(seq) << std::endl;
  if (!PmergeMe::isSorted(seq)) {
    std::cerr << "Error: std::vector is not sorted." << std::endl;
  }
  elapsedTime = (end.tv_usec - begin.tv_usec);
  elapsedTime += (end.tv_sec - begin.tv_sec) * 1000000;
  std::cout << "Time to process a range of " << seq.size() << " elements with "
            << type << ": " << elapsedTime << " us." << std::endl;
}

#endif // !BENCHMARK_HPP
