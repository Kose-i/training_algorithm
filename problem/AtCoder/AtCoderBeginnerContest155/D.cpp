#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  ll N, K;
  std::cin >> N >> K;
  std::vector<ll> A(N);
  rep(i, N) std::cin >> A[i];
  std::sort(A.begin(), A.end());
}
