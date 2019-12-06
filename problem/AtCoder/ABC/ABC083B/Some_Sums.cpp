#include <iostream>

unsigned from_sum(const int& end_num, const int& from, const int& to) {
  unsigned answer {};
  for (auto i = 0;i <= end_num;++i) {
    int n = i;
    unsigned sum_t {};
    while (n > 0) {
      sum_t += n % 10;
      n /= 10;
    }
    if (from <= sum_t && sum_t <= to) answer += i;
  }
  return answer;
}

int main(int argc, char** argv) {
  const int N {[](){int t;std::cin >> t;return t;}()};
  const int A {[](){int t;std::cin >> t;return t;}()};
  const int B {[](){int t;std::cin >> t;return t;}()};
  std::cout << from_sum(N, A, B) << '\n';
}
