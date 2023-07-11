/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:31:05 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/22 16:01:57 by vgoncalv         ###   ########.fr       */
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
  uint *straggler = NULL;
  std::vector<std::pair<uint, uint> > pairs;
  std::vector<uint> mainSeq, pendingSeq, jacobSeq, indexSeq;

  if (arr.size() < 2 or isSorted(arr)) {
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
  if (straggler != NULL)
    insertStraggler(mainSeq, *straggler);
  arr.assign(mainSeq.begin(), mainSeq.end());
}

void PmergeMe::sortDeque(std::deque<uint> &arr) {
  uint *straggler = NULL;
  std::deque<std::pair<uint, uint> > pairs;
  std::deque<uint> mainSeq, pendingSeq, jacobSeq, indexSeq;

  if (arr.size() < 2 or isSorted(arr)) {
    return;
  }
  if (hasStraggler(arr)) {
    straggler = &arr.back();
    arr.pop_back();
  }
  pairs = createDequePairs(arr);
  sortPairs(pairs);
  insertionSortByLargestValue(pairs, pairs.size());
  mainSeq = createDequeMainSeq(pairs);
  pendingSeq = createDequePendingSeq(pairs);
  jacobSeq = createJacobsthalSeq(pendingSeq);
  indexSeq = createIndexSeq(jacobSeq, pendingSeq);
  fillMainSeq(mainSeq, indexSeq, pendingSeq);
  if (straggler != NULL)
    insertStraggler(mainSeq, *straggler);
  arr.assign(mainSeq.begin(), mainSeq.end());
}


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

  for (it = pairs.begin(); it != pairs.end(); it++) {
    mainSeq.push_back(it->second);
  }
  return (mainSeq);
}

std::vector<uint>
PmergeMe::createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs) {
  std::vector<uint> mainSeq;
  std::vector<std::pair<uint, uint> >::iterator it;

  for (it = pairs.begin(); it != pairs.end(); it++) {
    mainSeq.push_back(it->first);
  }
  return (mainSeq);
}

std::deque<std::pair<uint, uint> >
PmergeMe::createDequePairs(std::deque<uint> &arr) {
  std::deque<uint>::iterator it, next;
  std::deque<std::pair<uint, uint> > pairs;

  it = arr.begin();
  while (it != arr.end()) {
    next = it + 1;
    pairs.push_back(std::make_pair(*it, *next));
    it += 2;
  }
  return (pairs);
}

std::deque<uint>
PmergeMe::createDequeMainSeq(std::deque<std::pair<uint, uint> > &pairs) {
  std::deque<uint> mainSeq;
  std::deque<std::pair<uint, uint> >::iterator it = pairs.begin();

  for (it = pairs.begin(); it != pairs.end(); it++) {
    mainSeq.push_back(it->second);
  }
  return (mainSeq);
}

std::deque<uint>
PmergeMe::createDequePendingSeq(std::deque<std::pair<uint, uint> > &pairs) {
  std::deque<uint> mainSeq;
  std::deque<std::pair<uint, uint> >::iterator it;

  for (it = pairs.begin(); it != pairs.end(); it++) {
    mainSeq.push_back(it->first);
  }
  return (mainSeq);
}


int PmergeMe::jacobsthal(int n) {
  if (n == 0)
    return (0);
  if (n == 1)
    return (1);
  return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}
