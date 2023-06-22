/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:16:25 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/22 12:52:40 by vgoncalv         ###   ########.fr       */
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
    return (NULL);
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
  std::vector<uint> vec;

  if (argc <= 2) {
    std::cerr << "Error: Not enough arguments." << std::endl;
    usage(argv[0]);
  }
  try {
    arr = parseArgs(argc - 1, argv + 1);
    vec = std::vector<uint>(arr, arr + (argc - 1));
    std::cout << "Before: " << seqToString(vec) << std::endl;
    PmergeMe::sortVec(vec);
    std::cout << "After: " << seqToString(vec) << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return (0);
}
