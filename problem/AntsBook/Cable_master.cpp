#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

double max(const std::vector<double>& vec) {
  double max_ = std::numeric_limits<double>::min();
  for (const auto& e : vec) {
    if (max_ < e) max_ = e;
  }
  return max_;
}
bool C(const int& N, const int& K, const std::vector<double>& L, const double& mid) {
  int sum {};
  for (const auto& e : L) {
    sum += (int)(e/mid);
  }
  return (sum >= K);
}
double answer(const int& N, const int& K, const std::vector<double>& L) {
  double left = 0.0, right = max(L);
  while (right - left >= 0.01) {
    double mid = (right+left)/2.0;
    if (C(N, K, L, mid) == true) left = mid;
    else right = mid;
  }
//  return left;//=right
  return std::floor(left*100)/100.0;//=right
}
int main(int argc, char** argv) {
  const int N {4};
  const int K {11};
  std::vector<double> L{8.02, 7.43, 4.57, 5.39};
  std::cout << answer(N, K, L) << '\n';
}
