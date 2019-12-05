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
int solve(const int& N, const int& R, std::vector<edge>& G, std::vector<int>& dist, std::vector<int>& dist2) {
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> que;
  for (auto& e : dist) e = INF;
  for (auto& e : dist2) e = INF;
  dist[0] = 0;
  que.push(Pair(0, 0));

  while (!que.empty()) {
    Pair p = que.top(); que.pop();
    int v = p.second, d = p.first;
    if (dist2[v] < d) continue;
    for (auto i = 0;i < G[v].size(); ++i) {
      edge &e = G[v][i];
      int d2 = d + e.cost;
      if (dist[e.to] > d2) {
        swap(dist[e.to], d2);
        que.push(Pair(dist[e.to], e.to));
      }
      if (dist2[e.to] > d2 && dist[e.to] < d2) {
        dist2[e.to] = d2;
        que.push(Pair(dist2[e.to], e.to));
      }
    }
  }
  return dist2[N-1];
}
int main(int argc, char** argv) {
  std::vector<edge> G(MAX_N);
  std::vector<int> dist(MAX_N);
  std::vector<int> dist2(MAX_N);
  int N {5};
  int R {3};
  std::cout << solve(N, R, G, dist, dist2) << '\n';
}
