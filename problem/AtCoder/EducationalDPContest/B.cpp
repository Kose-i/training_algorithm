#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using ll = long long;
#define rep(i, n) for(int i=0;i<(n);++i)

int main(int argc, char** argv) {
  ll N, K;
  std::cin >> N >> K;
  std::vector<ll> h(N);
  rep(i, N) std::cin >> h[i];
  std::vector<ll> H;
  if (h[0] < h[N-1]) {
    H = h;
  } else {
    H = std::vector<ll>(h.rbegin(), h.rend());
  }
}
