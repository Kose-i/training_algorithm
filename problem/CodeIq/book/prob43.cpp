#include <iostream>
#include <vector>

namespace prob43{
  unsigned long long seat(const int& n, const int& size, std::vector<int>& memo) {
    if (memo[n]) return memo[n];
    unsigned long long count1 {};
    for (int tmp = 1;tmp != 0;tmp=tmp<<1) {
      if (n & tmp) ++count1;
    }
    long pre  = count1 - 1;
    long post = count1 % size;
    unsigned long long cnt {};
    for (auto i = 0;i < size;++i) {
      int mask = (1<<i);
      if (((n & mask) > 0) && (i != pre) && (i != post)) {
        cnt += seat(n - mask, size, memo);
      }
    }
    return memo[n] = cnt;
  }
  unsigned long long factorial(const int& n) {
    unsigned long long ans = {1};
    for (auto i = 1;i <= n;++i) {
      ans *= i;
    }
    return ans;
  }
  unsigned long long answer(const int& size) {
    std::vector<int> memo(1<<size, 0);
    memo[0] = 1;
    return seat((1<<size) - 1, size, memo) * factorial(size - 1);
  }
}

int main(int argc, char** argv) {
  const int size {7};
  std::cout << prob43::answer(size) << '\n';
}
