/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:16:25 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/22 16:05:39 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "benchmark.hpp"
#include <iostream>
#include <stdexcept>

static void usage(const char *pname) {
  std::cerr << "Usage: " << pname << " <sequence...>" << std::endl
            << std::endl
            << "Benchmarks the Ford-Johnson algorithm using std::vector and "
               "std::list C++ STL sequence containers."
            << std::endl
            << std::endl
            << "Arguments:" << std::endl
            << "  <sequence...>  A sequence of non-negative numbers."
            << std::endl;
}

static uint *parseArgs(int argc, char **argv) {
  uint *arr;

  if (argc < 2) {
    throw std::runtime_error("Expected a sequence of two or more numbers.");
  }
  arr = new uint[argc]();
  for (int i = 0; i < argc; i++) {
    int n = std::atoi(argv[i]);
    if (n < 0) {
      throw std::runtime_error("Expected a sequence of non-negative numbers.");
    }
    arr[i] = static_cast<uint>(n);
  }
  return (arr);
}

int main(int argc, char **argv) {
  uint *arr = NULL;

  try {
    arr = parseArgs(argc - 1, argv + 1);
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    usage(argv[0]);
    return (1);
  }
  std::vector<uint> vec(arr, arr + argc - 1);
  std::deque<uint> deq(arr, arr + argc - 1);
  benchSort("std::vector", vec, PmergeMe::sortVec);
  benchSort("std::deque", deq, PmergeMe::sortDeque);
  return (0);
}
