#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
  const int n = 5;
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{1, 0, 1, 0, 1};
  std::sort(v1.begin(), v1.end());
  std::sort(v2.rbegin(), v2.rend());
  long long sum {};
  for (auto i = 0;i < n;++i) {
    sum += v1[i]*v2[i];
  }
  std::cout << sum << '\n';
}
