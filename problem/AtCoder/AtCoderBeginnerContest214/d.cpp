#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <utility>

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

using Pair = std::pair<int, ll>; 
struct Node {
  vector<Pair> path;
};

struct AnswerType {
  ll node_cnt; // now minim tree answer
  ll node_weights; // maximum depth
  ll max_path;
};

AnswerType dfs(const int& now_pos, const int& from_pos, const vector<Node>& tree_weights, const int& n) {
  AnswerType ans;
  ans.node_cnt = 0;
  ans.node_weights = 0;
  for (const Pair& e : tree_weights[now_pos].path) {
    if (e.first == from_pos) continue;
    AnswerType t = dfs(e.first, now_pos, tree_weights, n);
    if (t.max_path < e.second)  t.max_path = e.second;
    ans.node_cnt += t.node_cnt;
    ans.node_weights += t.node_weights;
    ans.node_weights += t.node_cnt*(n-t.node_cnt)*t.max_path;
    ans.max_path = t.max_path;
  }
  ++ans.node_cnt;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Node> tree_path(n);
  rep(i, n-1) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    tree_path[u-1].path.push_back(Pair{v-1, w});
    tree_path[v-1].path.push_back(Pair{u-1, w});
  }
  AnswerType ans = dfs(0, -1, tree_path, n);
  cout << ans.node_weights/2 << '\n';
}