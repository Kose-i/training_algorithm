#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main() {
  int N;
  std::cin >> N;
  std::vector<ll> B(N-1);
  rep(i,N-1) std::cin >> B[i];
  std::vector<ll> A(N);
  A[0] = B[0];
  for (auto i = 1;i < N;++i) {
    A[i] = std::min(B[i-1], B[i]);
  }
  A[N-1] = B[N-2];
  ll sum {};
  for (const auto& e : A) {
    sum += e;
  }
  std::cout << sum << '\n';
}
