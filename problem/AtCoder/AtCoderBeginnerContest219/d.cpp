#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using Pair = std::pair<int, int>;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

struct edge{
  int to, cap, rev;
};

constexpr int min(int a, int b) {
  return (a<b)?a:b;
}
constexpr int INF {10000000};
class MaxFlow{ // Ford-Fullkerson
  private:
    int N_;
    std::vector<std::vector<edge>> G;
    std::vector<char> used;
  public:
    MaxFlow(const int& N) : N_(N), G(N, std::vector<edge>()), used(N, 0) {}
    void add_edge(const int& from, const int& to, const int& cap) {
      G[from].push_back((edge){to, cap, (int)G[to].size()});
      G[to].push_back((edge){from, 0, (int)G[from].size()-1});
    }
    int max_flow(const int& s, const int& t) {
      int flow {};
      for (;;) {
        std::for_each(used.begin(), used.end(), [](auto& e){e=0;});
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
      }
      return 0;
    }
  private:
    int dfs(const int& v, const int& t, const int& f) {
      if (v==t) return f;
      used[v] = 1;
      for (auto i = 0;i < G[v].size();++i) {
        edge &e = G[v][i];
        if (used[e.to]==0 && e.cap>0) {
          int d = dfs(e.to, t, min(f, e.cap));
          if (d > 0) {
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
          }
        }
      }
      return 0;
    }
};

struct Path{
  int from, to, cap;
};

int main(int argc, char** argv) {
  int n, x, y;
  cin >> n >> x >> y;
  vector<Pair> a(n);
  rep(i, n) cin >> a[i].first >> a[i].second;

  {
    MaxFlow m(n+5);
    for (auto i = 0;i < n;++i) {
        m.add_edge(i+2, n+2, a[i].first);
        m.add_edge(i+2, n+3, a[i].second);
        m.add_edge(1, i+2, 1);
    }
    m.add_edge(0, 1, n);
    m.add_edge(n+2, n+4, x);
    m.add_edge(n+3, n+4, y);
    if (m.max_flow(0, n+4) < x+y) {
        cout << "-1\n";
        return 0;
    }
  }

  int left {};
  int right {n};
  for (int mid= (left + right)/2;right - left > 1;) {
    mid = (left+right)/2;
    MaxFlow m(n+5);
    for (auto i = 0;i < n;++i) {
        m.add_edge(i+2, n+2, a[i].first);
        m.add_edge(i+2, n+1, a[i].second);
        m.add_edge(1, i+2, 1);
    }
    m.add_edge(0, 1, mid);
    m.add_edge(n+2, n+4, x);
    m.add_edge(n+3, n+4, y);
    if (m.max_flow(0, n+4) == x+y) right = mid;
    else left = mid;
  }
  std::cout << right << '\n';
}
