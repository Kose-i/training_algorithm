#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

struct P{
  ll cost;
  int index;
};

int main(int argc, char** argv) {
  ll N, C;
  std::cin >> N >> C;
  std::vector<ll> h(N);
  rep(i, N) std::cin >> h[i];
}
