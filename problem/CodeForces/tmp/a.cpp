#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

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

  int times_n; cin >> times_n;
  vector<int> n(times_n);
  vector<int> x(times_n);
  vector<vector<int>> weights(times_n);
  rep(i, times_n) {
    cin >> n[i] >> x[i];
    vector<int> weight_tmp(n[i]);
    rep(j, n[i]) cin >> weight_tmp[j];
    std::sort(weight_tmp.rbegin(), weight_tmp.rend());
    weights[i] = weight_tmp;
  }

  rep(i, times_n) {
    bool is_ok {true};
    int cumul_weight {};
    rep(j, n[i]) {
      cumul_weight += weights[i][j];
      if (cumul_weight == x[i]) {
        is_ok = false;
        break;
      }
    }
    if (is_ok == false) {
      rep(j, n[i]) {
        cumul_weight += weights[i][n[i] - 1 - j];
        if (cumul_weight == x[i]) {
          is_ok = false;
          break;
        }
      }
    } else {
      bool is_first {true};
      cout << "YES\n";
      rep(j, n[i]) {
        if (is_first) is_first = false;
        else cout << ' ';
        cout << weights[i][j];
      }
      cout << '\n';
      continue;
    }
    if (is_ok == false) {
      cout << "NO\n";
    } else {
      bool is_first {true};
      cout << "YES\n";
      rep(j, n[i]) {
        if (is_first) is_first = false;
        else cout << ' ';
        cout << weights[i][n[i] - 1 - j];
      }
      cout << '\n';
    }
  }
}
