#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
  std::cout << std::fixed << std::setw(8);
  int N;
  std::cin >> N;
  int k = (N+1)/2;
  double c = k/static_cast<double>(N);
  std::cout << c << '\n';
}
