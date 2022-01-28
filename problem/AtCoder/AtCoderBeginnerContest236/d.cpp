#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Pair = std::pair<int, int>;

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

struct Query {
  vector<Pair> a;
  vector<char> is_used;
  int idx;
};
ll calc(const vector<Pair>& retu, const vector<vector<ll>>& conmat) {
  ll ans {};
  for (const Pair& e : retu) {
    ans^= conmat[e.first][e.second];
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<ll>> a(2*n, vector<ll>(2*n));
  rep(i, 2*n) {
    for (int j=i+1;j<2*n;++j) {
      cin >> a[i][j];
    }
  }

  vector<char> is_used(2*n, 0);
  queue<Query> que;
  Query first_query;
  first_query.is_used = is_used;
  first_query.idx = 0;
  que.push(first_query);
  for (int i=0;i<n;++i) {
    queue<Query> next_que;
    for (;!que.empty();) {
      Query tmp = que.front(); que.pop();
      for (;tmp.is_used[tmp.idx]==1;++tmp.idx);
      Pair next_p; next_p.first = tmp.idx;
      tmp.is_used[tmp.idx] = 1;
      for (;tmp.is_used[tmp.idx]==1;++tmp.idx);
      tmp.is_used[tmp.idx] = 1;
      next_p.second = tmp.idx;
      tmp.a.push_back(next_p);
      next_que.push(tmp);
      tmp.is_used[tmp.idx] = 0;
      for (int c = tmp.idx+1;2*n!=c;++c) {
        if (tmp.is_used[c] == 0) {
          next_p.second = c;
          tmp.a[tmp.a.size()-1] = next_p;
          tmp.is_used[c] = 1;
          next_que.push(tmp);
          tmp.is_used[c] = 0;
        }
      }
    }
    que = next_que;
  }
  //cout << que.size() << '\n';
  ll ans  {};
  for (;!que.empty();) {
    Query tmp = que.front(); que.pop();
    //for (const auto& e : tmp.a) cout << '(' <<e.first << ',' << e.second << ')' << ',';
    //cout << '\n';
    maxs(ans, calc(tmp.a, a));
  }
  cout << ans << '\n';
}