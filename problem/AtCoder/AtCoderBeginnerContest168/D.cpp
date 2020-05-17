#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <list>
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

using P = std::pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> path(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    path[a].push_back(b);
    path[b].push_back(a);
  }

  vector<int> X(n, -1);
  X[0] = 0;
  std::queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int c = que.front(); que.pop();
    for (const auto& to : path[c]) {
      if (X[to] == -1) {
        X[to] = c;
        que.push(to);
      }
//      if (c == tmp.first) {
//        if (X[tmp.second] == -1) {
//          X[tmp.second] = tmp.first;
//          que.push(tmp.second);
// //         cout << X[tmp.second] << '\n';
//        }
//        if (it != path.begin()) --it;
//        path.remove(tmp);
//      } else if (c == tmp.second){
//        if (X[tmp.first] == -1) {
//          X[tmp.first] = tmp.second;
//          que.push(tmp.first);
////          cout << X[tmp.first] << '\n';
//        }
//        if (it != path.begin()) --it;
//        path.remove(tmp);
////        --it;
////        path.erase(it);
//      }
    }
  }

  rep(i, n) {
    if (X[i] == -1) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  srep(i,1,n) {
    cout << X[i]+1 << '\n';
  }
}
