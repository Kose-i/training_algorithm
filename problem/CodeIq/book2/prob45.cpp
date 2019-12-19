#include <iostream>

namespace prob45{
  unsigned answer(const int& n_points) {
    if (n_points <= 3) return 0;
    unsigned factorial {1};
    for (auto i = 1;i <= n_points;++i) {
      factorial *= i;
    }
    return factorial*(n_points - 3)/6;
  }
}

int main(int argc, char** argv) {
  const int points {9};
  std::cout << prob45::answer(points) << '\n';
}
