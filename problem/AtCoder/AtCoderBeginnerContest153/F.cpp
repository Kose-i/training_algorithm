#include <iostream>
#include <vector>
#include <algorithm>

struct P {
  long long X;
  long long H;
};

int main(int argc, char** argv) {
  long long N, D, A;
  std::cin >> N >> D >> A;
  std::vector<P> Monsters(N);
  for (auto& e : Monsters) std::cin >> e.X >> e.H;
  std::sort(Monsters.begin(), Monsters.end(), [](const auto& l, const auto& r){return (l.X<r.X);});
  unsigned long cnt {};
  int min_index {};
  for (;;) {
    int start_pos {};
    for (start_pos = min_index;start_pos < N;++start_pos) {
      if (Monsters[start_pos].H > 0) {
        min_index = start_pos + 1;
        break;
      }
    }
    if (start_pos == N) break;
    unsigned long long atack_power = A * (Monsters[start_pos].H/A);
    cnt += Monsters[start_pos].H/A;
    if (Monsters[start_pos].H % A != 0) {
      atack_power += A;
      ++cnt;
    }
    Monsters[start_pos].H = 0;
    for (auto j = start_pos+1;j < N;++j) {
      if (Monsters[j].X <= Monsters[start_pos].X + 2*D) {
        if (Monsters[j].H < atack_power) {
          Monsters[j].H = 0;
        } else {
          Monsters[j].H -= atack_power;
        }
      } else {
        break;
      }
    }
  }
  std::cout << cnt << '\n';
}
