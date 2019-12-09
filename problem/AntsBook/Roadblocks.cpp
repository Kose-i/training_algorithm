#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using Pair = std::pair<int, int>;
constexpr int INF {std::numeric_limits<int>::max()};
struct edge{
  int from, to;
  int cost;
};
constexpr int MAX_N {5000};

void swap(int& t1, int& t2) {
  int tmp = t1;
  t1 = t2;
  t2 = tmp;
}
int solve(const int& N, const int& R, std::vector<edge>& G) {
  std::vector<int> dist(MAX_N);
  std::vector<int> dist2(MAX_N);
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> que;
  for (auto& e : dist) e = INF;
  for (auto& e : dist2) e = INF;
  dist[0] = 0;
  que.push(Pair(0, 0));

  while (!que.empty()) {
    Pair p = que.top(); que.pop();
    int d = p.first;  // cost
    int v = p.second; // pos
    if (dist2[v] < d) continue;
    for (const auto& e : G) {
      if (e.from == v) {
        int d2 = d + e.cost;//e.to のコスト
        if (dist[e.to] > d2) {
          swap(dist[e.to], d2);
          que.push(Pair(dist[e.to], e.to));
        }
        if (d2 < dist2[e.to] && dist[e.to] < d2) { // dist[e.to] != d2
          dist[e.to] = d2;
          que.push(Pair(dist2[e.to], e.to));
        }
      } else if (e.to == v) {
        int d2 = d + e.cost;//e.from のコスト
        if (dist[e.from] > d2) {
          swap(dist[e.from], d2);
          que.push(Pair(dist[e.from], e.from));
        }
        if (d2 < dist2[e.from] && dist[e.from] < d2) { // dist[e.from] != d2
          dist[e.from] = d2;
          que.push(Pair(dist2[e.from], e.from));
        }
      }
    }
  }
  return dist2[N-1];
}
int main(int argc, char** argv) {
  std::vector<edge> G;
  edge t;
  t.from = 1; t.to = 2; t.cost = 100;
  G.push_back(t);
  t.from = 2; t.to = 3; t.cost = 250;
  G.push_back(t);
  t.from = 2; t.to = 4; t.cost = 200;
  G.push_back(t);
  t.from = 3; t.to = 4; t.cost = 100;
  G.push_back(t);
  int N {4};
  int R {4};
  std::cout << solve(N, R, G) << '\n';
}
