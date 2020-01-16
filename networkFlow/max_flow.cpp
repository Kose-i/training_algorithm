#include <algorithm>
#include <iostream>
#include <vector>

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
  MaxFlow m(6);
  std::vector<Path> p {{0,1,9},
                       {0,2,9},
                       {1,2,1},
                       {1,3,3},
                       {1,4,7},
                       {2,4,8},
                       {4,3,5},
                       {3,5,9},
                       {4,5,9}};
  for (auto& e : p) {
    m.add_edge(e.from, e.to, e.cap);
  }
  std::cout << m.max_flow(0, 5) << '\n';
}
