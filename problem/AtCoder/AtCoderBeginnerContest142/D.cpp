#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main(int argc, char** argv) {
  unsigned long long A, B;
  std::cin >> A >> B;
  unsigned long long max_yakusuu = gcd(A, B);
  std::vector<int> prime_cnt(max_yakusuu+1, 1);
  std::iota(prime_cnt.begin(), prime_cnt.end(), 0);
  prime_cnt[0] = prime_cnt[1] = 0;
  int cnt {1};
  for (auto i = 2;i <= max_yakusuu;++i) {
    if (prime_cnt[i] == 0) continue;
    for (auto j = i+i;j <= max_yakusuu;j += i) {
      prime_cnt[j] = 0;
    }
    if (max_yakusuu % prime_cnt[i] == 0) {
      ++cnt;
    }
  }
  std::cout << cnt << '\n';
}
