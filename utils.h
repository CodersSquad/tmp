#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <queue>
#include <chrono>
#include <random>

namespace utils {

  template<typename T>
  void pop_println(std::string_view rem, T& pq) {
    std::cout << rem << ": ";
    for (; !pq.empty(); pq.pop())
      std::cout << pq.top() << ' ';
    std::cout << '\n';
  }
 
  template<typename T>
  void pop_front_println(std::string_view rem, T& pq) {
    std::cout << rem << ": ";
    for (; !pq.empty(); pq.pop())
      std::cout << pq.front() << ' ';
    std::cout << '\n';
  }

  template<typename T>
  void println(std::string_view rem, const T& v) {
    std::cout << rem << ": ";
    for (const auto& e : v)
      std::cout << e << ' ';
    std::cout << '\n';
  }

  int generateRandomInt(int min, int max);
}
#endif // UTILS_H
