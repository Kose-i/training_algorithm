#include <iostream>
#include <vector>

#define rep(i, n) for(int i = 0;i < (n);++i)

using ll = long long;

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<ll> h(N);
  std::vector<ll> a(N);
  rep(i, N) std::cin >> h[i];
  rep(i, n) std::cin >> a[i];
}
