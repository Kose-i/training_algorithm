#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main() {
  ll N, M;
  std::cin >> N >> M;
  std::vector<ll> A(N);
  rep(i, N) std::cin >> A[i];
  std::sort(A.begin(), A.end(), std::greater<ll>());
  for (auto i = 0;i < M;++i) {
    if (i >= N) std::sort(A.rbegin(), A.rend());
    if (i >= N) std::sort(A.begin(), A.end(), std::greater<ll>());
    else std::sort(A.begin(), A.begin()+i, std::greater<ll>());
    A[0] /= 2;
  }
  ll answer {};
  for (const auto& e : A) {
    answer  += e;
  }
  std::cout << answer << '\n';
}
