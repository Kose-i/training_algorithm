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
class MaxMatching{
  private:
    int N_;
    std::vector<std::vector<edge>> G;
    std::vector<char> used;
  public:
    MaxMatching(const int& N) : N_(N), G(N, std::vector<edge>()), used(N, 0) {}
    void add_edge(const int& from, const int& to) {
      G[from].push_back((edge){to, 1, (int)G[to].size()}); // max_flow の容量を1とする
      G[to].push_back((edge){from, 0, (int)G[from].size()-1});
    }
    int max_matching(const int& s, const int& t) {
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

struct Pair{
  int R, C;
};
int answer(const int& N, const int& K, const std::vector<Pair>& RC) {
  MaxMatching m(2*N+2);
  for (auto i = 0;i < N;++i) {
    m.add_edge(0, i+1);
    m.add_edge(N+i+1, 2*N+1);
  }
  for (auto i = 0;i < K;++i) {
    m.add_edge(RC[i].R, RC[i].C+N);
  }
  return m.max_matching(0, N+1);
}

int main(int argc, char** argv) {
  int N {3};
  int K {4};
  std::vector<Pair> RC {{1, 1}, {1, 3}, {2, 2}, {3, 2}};
  std::cout << answer(N, K, RC) << '\n';
}
