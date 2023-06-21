/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:16:25 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/21 19:54:07 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

template <class T> void printVec(std::vector<T> &vec) {
  typename std::vector<T>::iterator it;

  for (it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it;
    if (it + 1 != vec.end()) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

int main(void) {
  int arr[] = {26, 70, 32, 2,  49,  9,  96, 42, 25, 11, 41, 14, 30, 35, 18,
               93, 4,  28, 47, 21,  65, 17, 34, 48, 83, 46, 38, 33, 95, 37,
               97, 19, 31, 98, 74,  15, 76, 92, 75, 7,  1,  64, 13, 90, 20,
               23, 82, 55, 50, 100, 66, 84, 71, 54, 67, 88, 3,  36, 72, 73,
               62, 68, 27, 58, 12,  80, 5,  22, 29, 51, 45, 63, 99, 85, 86,
               40, 60, 39, 69, 16,  57, 59, 78, 81, 43, 52, 44, 61, 91, 56,
               87, 10, 6,  89, 77,  24, 94, 8,  53, 79, 101};
  std::vector<uint> vec(arr, arr + (sizeof(arr) / sizeof(int)));

  printVec(vec);
  PmergeMe::sortVec(vec);
  printVec(vec);
  return (0);
}
