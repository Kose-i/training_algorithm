#include <iostream>
#include <vector>
#include <algorithm>
/*
提出 #9750607を参考にしました
*/

struct P {
  long long X;
  long long H;
};

constexpr unsigned long max_monsters_hp{1000000000};

int main(int argc, char** argv) {
  long long N, D, A;
  std::cin >> N >> D >> A;
  std::vector<P> Monsters(N);
  for (auto& e : Monsters) std::cin >> e.X >> e.H;
  std::sort(Monsters.begin(), Monsters.end(), [](const auto& l, const auto& r){return (l.X<r.X);});

  long long ans {};
  std::vector<long long> c(N+1);
  for (auto i = 0;i < N;++i) {
    c[i]   += Monsters[i].H;
    c[i+1] -= Monsters[i].H;
  }

  for (auto i = 0;i < N;++i) {
    if (i) c[i] += c[i-1];
    if (c[i] > 0) {
      long long cnt = (c[i] + A - 1) / A;
      ans += cnt;
      P tmp {Monsters[i].X + 2*D + 1, 0};
      int index = std::lower_bound(Monsters.begin(), Monsters.end(), tmp, [](auto& l, auto& r){return l.X<r.X;}) - Monsters.begin();
      c[i] -= cnt*A;
      c[index] += cnt*A;
    }
  }
  std::cout << ans << '\n';
}
