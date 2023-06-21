/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:31:05 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/21 19:58:07 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
  return (*this);
}

void PmergeMe::sortVec(std::vector<uint> &arr) {
  uint *straggler = NULL; // clang-format off
  std::vector<std::pair<uint, uint> > pairs; // clang-format on
  std::vector<uint> mainSeq, pendingSeq, jacobSeq, indexSeq;

  if (arr.size() < 2) {
    return;
  }
  if (hasStraggler(arr)) {
    straggler = &arr.back();
    arr.pop_back();
  }
  pairs = createVectorPairs(arr);
  sortPairs(pairs);
  insertionSortByLargestValue(pairs, pairs.size());
  mainSeq = createVectorMainSeq(pairs);
  pendingSeq = createVectorPendingSeq(pairs);
  jacobSeq = createJacobsthalSeq(pendingSeq);
  indexSeq = createIndexSeq(jacobSeq, pendingSeq);
  fillMainSeq(mainSeq, indexSeq, pendingSeq);
  insertStraggler(mainSeq, *straggler);
  arr.assign(mainSeq.begin(), mainSeq.end());
}

// clang-format off
std::vector<std::pair<uint, uint> >
PmergeMe::createVectorPairs(std::vector<uint> &arr) {
  std::vector<uint>::iterator it, next;
  std::vector<std::pair<uint, uint> > pairs;

  it = arr.begin();
  while (it != arr.end()) {
    next = it + 1;
    pairs.push_back(std::make_pair(*it, *next));
    it += 2;
  }
  return (pairs);
}

std::vector<uint>
PmergeMe::createVectorMainSeq(std::vector<std::pair<uint, uint> > &pairs) {
  std::vector<uint> mainSeq;

  std::vector<std::pair<uint, uint> >::iterator it = pairs.begin();
  mainSeq.push_back(it->first);
  for (; it != pairs.end(); it++) {
    mainSeq.push_back(it->second);
  }
  return (mainSeq);
}

std::vector<uint>
PmergeMe::createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs) {
  std::vector<uint> mainSeq;

  std::vector<std::pair<uint, uint> >::iterator it;
  for (it = pairs.begin() + 1; it != pairs.end(); it++) {
    mainSeq.push_back(it->first);
  }
  return (mainSeq);
}
// clang-format on

int PmergeMe::jacobsthal(int n) {
  if (n <= 1)
    return (n);
  return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}
