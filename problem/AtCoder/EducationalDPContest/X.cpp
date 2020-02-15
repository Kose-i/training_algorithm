#include <iostream>
#include <vector>

using ll = long long;
#define rep(i, n) for(int i = 0;i < (n);++i)
struct P{
  ll w, s, v;
};

int main(int argc, char** argv) {
  ll N;
  std::cin >> N;
  std::vector<P> Data(N);
  rep(i, N) std::cin >> Data[i].w >> Data[i].s >> Data[i].v;
}
