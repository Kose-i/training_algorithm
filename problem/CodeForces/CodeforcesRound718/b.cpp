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

  for (auto t = 0;t < times_n;++t) {
    int node_cnt; cin >> node_cnt;
    int path_cnt; cin >> path_cnt;
    std::vector<std::vector<int>> table(node_cnt, std::vector<int>(path_cnt, 0));
    rep(i, node_cnt) {
      rep(j, path_cnt) {
        cin >> table[i][j];
      }
      std::sort(table[i].begin(), table[i].end());
    }

    std::vector<std::vector<int>> ans(node_cnt, std::vector<int>(path_cnt, 0));
    {
      std::vector<int> min_idx(node_cnt, 0);
      std::vector<int> max_idx(node_cnt, path_cnt-1);
      for (auto p = 0;p < path_cnt;++p) {
        int min_idx_tmp{0};
        int min_val{table[0][min_idx[0]]};
        for (int i = 1; i < node_cnt; ++i) {
          if (table[i][min_idx[i]] < min_val) {
            min_val = table[i][min_idx[i]];
            min_idx_tmp = i;
          }
        }
        for (auto i = 0;i < node_cnt;++i) {
          if (min_idx_tmp != i) {
            ans[i][p] = max_idx[i];
            --max_idx[i];
          } else {
            ans[i][p] = min_idx[i];
            ++min_idx[i];
          }
        }
      }
    }
    rep(i, node_cnt) {
      bool is_first {true};
      rep(j, path_cnt) {
        if (is_first) {
          is_first = false;
        } else {
          cout << ' ';
        }
        cout << table[i][ans[i][j]];
      }
      cout << '\n';
    }
  }
}
