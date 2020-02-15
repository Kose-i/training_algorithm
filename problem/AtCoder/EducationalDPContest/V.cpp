#include <iostream>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  ll N, M;
  std::cin >> N >> M;
  std::vector<P> X(N);
  rep(i, N) std::cin >> X[i].first >> X[i].second;
}
