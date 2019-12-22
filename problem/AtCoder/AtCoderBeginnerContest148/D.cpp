#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  const int N {[](){int a;std::cin >> a;return a;}()};
  std::vector<int> a(N);
  for (auto& e : a) {
    std::cin >> e;
  }
  int sum {};
  int num {1};
  for (const auto& e : a) {
    if (e != num) {
      ++sum;
    } else {
      ++num;
    }
  }
  if (sum == N) sum = -1;
  std::cout << sum << '\n';
}
