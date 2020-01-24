#include <iostream>
#include <vector>
#include <cmath>

struct Pos {
  double x, y;
};
long double diff(const Pos& l, const Pos& r) {
  return std::sqrt(std::pow(std::abs(l.x-r.x), 2) + std::pow(std::abs(l.y-r.y), 2));
}
int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<Pos> country(N);
  for (auto& e : country) {
    std::cin >> e.x >> e.y;
  }
  std::vector<double> factorial(N+1);
  factorial[0] = 1;
  for (auto i = 1;i <= N;++i) {
    factorial[i] = factorial[i-1]*i;
  }
  long double sum {0.0};
  for (auto i = 0;i < N;++i) {
    for (auto j = i+1;j < N;++j) {
      sum += diff(country[i], country[j])*factorial[N-1]*2;
    }
  }
  std::cout << sum/factorial[N] << '\n';
}
