#include <iostream>
#include <vector>

using ll = long long;

struct P{
  ll x, y;
};

int main(int argc, char** argv) {
  ll n;
  std::cin >> n;
  std::vector<P> Path(n-1);
  rep(i, n-1) std::cin >> Path[i].x >> Path[i].y;
}
