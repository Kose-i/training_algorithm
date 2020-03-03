#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main() {
  ll N, K, Q;
  std::cin >> N >> K >> Q;
  std::vector<ll> A(Q);
  rep(i,Q) std::cin >> A[i];
  ll res_point {0};
  std::vector<ll> Player(N, K);
  rep(i,Q) {
    if (Player[A[i] - 1] - res_point > 0) ++Player[A[i] - 1];
    ++res_point;
  }
  rep(i,N) {
    if (Player[i] - res_point > 0) std::cout << "Yes\n";
    else std::cout << "No\n";
  }
}
