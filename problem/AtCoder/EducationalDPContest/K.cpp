#include <iostream>
#include <vector>
#include <bitset>

#define rep(i, n) for(int i = 0;i < (n);++i)
using ll = long long;
constexpr ll MAX_K {100000+1};


int main(int argc, char** argv) {
  int N, K;
  std::cin >> N >> K;
  std::vector<ll> a(N, 0);
  rep(i, N) std::cin >> a[i];
  std::bitset<MAX_K> win(0uL);
  for (auto i = 1;i <= K;++i) {
    //win[i]
    rep(j,N) {
      if (a[j] <= i && !win[i-a[j]]) {
        win.set(i);
      }
    }
  }
  std::cout << (win[K]?"First\n":"Second\n");
}
