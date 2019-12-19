#include <iostream>

namespace prob49{
  unsigned answer(const int& min_expect) {
    unsigned m {};
    double sum {};
    while (sum <= min_expect) {
      ++m;
      sum += 1.0/m;
    }
    return m;
  }
}
int main(int argc, char** argv) {
  const int minimum_expectation {10};
  std::cout << prob49::answer(minimum_expectation) << '\n';
}
