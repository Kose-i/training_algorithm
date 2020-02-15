#include <iostream>
#include <vector>

using ll = long long;

#define rep(i,n) for(int i = 0;i < (n);++i)

struct P{
  ll x, y;
};

int main(int argc, char** argv) {
  ll N, M;
  std::cin >> N >> M;
  std::vector<P> Path(M);
  rep(i, M) std::cin >> Path[i].x >> Path[i].y;
  std::vector<ll> Node(N+1, 0);
  for (const auto& e : Path) {
    ++Node[e.x];
  }
  for (bool is_update = true;is_update == true;) {
    is_update = false;
    for (const auto& e : Path) {
      if (Node[e.x] >= Node[e.y]+1)continue;
      Node[e.x] = Node[e.y]+1;
      is_update = true;
    }
  }
  ll max_path {};
  for (const auto& e : Node) {
    max_path = std::max(max_path, e);
  }
  std::cout << max_path << '\n';
}
