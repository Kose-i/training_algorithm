#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <utility>

using Pair = std::pair<int,int>;

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF
constexpr int INTINF {1000000000};//int = 2*INTINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T&& y) {
  x=std::max(x,y);
}
template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T&& y) {
  x=std::min(x,y);
}
template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}


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
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  std::vector<Pair> data(n);
  std::map<int, int> colormap;
  int idx {1};
  rep(i, n) {
    cin >> data[i].first >> data[i].second;
    if (colormap[data[i].first] == 0) {
      colormap[data[i].first] = idx;
      ++idx;
    }
    if (colormap[data[i].second] == 0) {
      colormap[data[i].second] = idx;
      ++idx;
    }
  }
  int color_cnt = colormap.size();
  MaxFlow m(n+1 + color_cnt + 2);
  for (auto i = 1;i <= n;++i) {
    m.add_edge(0, i, 1);
  }
  for (auto i = 0;i < color_cnt;++i) {
    m.add_edge(1+i, n+colormap[data[i].first], 1);
    m.add_edge(1+i, n+colormap[data[i].second], 1);
  }
  for (auto i = 0;i < color_cnt;++i) {
    m.add_edge(n+1+i, n+1+color_cnt+1, 1);
  }

  std::cout << m.max_flow(0, n+1+color_cnt+1) << '\n';
}
