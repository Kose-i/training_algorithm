#include <iostream>
#include <vector>
#include <map>

struct Pos {
  int y, x;
};
bool operator<(const Pos l, const Pos r) {
  return ((l.y == r.y)?(l.x < r.x):(l.y < r.y));
}
Pos operator+(const Pos& l, const Pos& r) {
  Pos t; t.y = l.y + r.y; t.x = l.x + r.x;
  return t;
}

const std::vector<Pos> directions{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
constexpr int N {12};

int search(const Pos& now_pos, std::map<Pos, int> mp, const int& n) {
  if (n == N) return 1;
  int ans {};
  for (const auto& e : directions) {
    Pos next_pos = now_pos + e;
    if (mp[next_pos] == 1) {
      continue;
    } else {
      std::map<Pos, int> new_mp = mp;
      new_mp[next_pos] = 1;
      ans += search(next_pos, new_mp, n+1);
    }
  }
  return ans;
}
int main(int argc, char** argv) {
  std::map<Pos, int> pos_map;
  Pos first_pos{0, 0};

  pos_map[first_pos] = 1;
  int ans = search(first_pos, pos_map, 0);
  std::cout << ans << '\n';
}
