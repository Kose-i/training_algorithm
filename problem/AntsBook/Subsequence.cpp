#include <algorithm>
#include <iostream>
#include <vector>

constexpr int min(int a, int b) {
  return (a<b)?a:b;
}
int answer(const int& n, const int& S, const std::vector<int>& a) {
  std::vector<int> sum(n+1, 0);
  for (auto i = 0;i < n;++i) {
    sum[i + 1] = sum[i] + a[i];
  }
  if (sum[n] < S) {
    return -1;
  }
  int res = n;
  for (int s = 0; sum[s] + S <= sum[n];++s) {
    int t = std::lower_bound(sum.begin()+s, sum.end()+n, sum[s]+S) - sum.begin();
    res = min(res, t-s);
  }
  return res;
}

int main(int argc, char** argv) {
  const int n {10};
  const int S {15};
  std::vector<int> a {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
  std::cout << answer(n, S, a) << '\n';
}
