#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int m;
  cin >> m;
  int n {9};
  vector<vector<int>> path(n);
  for (int i=0;i<m;++i) {
    int u, v;
    cin >> u >> v;
    path[u-1].push_back(v-1);
    path[v-1].push_back(u-1);
  }
  std::string s = "999999999";
  for (int i=1;i<=8;++i) {
    int t;
    cin >> t;
    s[t-1] = '0'+i;
  }
  //cout << s << '\n';
  queue<string> que;
  map<string, int> mp;
  que.push(s);
  mp[s] = 1;

  for (;!que.empty();) {
    string t = que.front(); que.pop();
    //cout << t << ',';
    int idx {};
    for (;idx < n;++idx) if (t[idx] == '9') break;
    for (int& e : path[idx]) {
      string next = t;
      next[idx] = next[e];
      next[e] = '9';
      if (mp[next] == 0) {
        que.push(next);
        mp[next] = mp[t] + 1;
      }
    }
  }
  cout << mp["123456789"]-1 << '\n';
}
