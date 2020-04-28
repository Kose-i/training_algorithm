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

  int H, W;
  cin >> H >> W;
  vector<vector<char>> Board(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> Board[i][j];
  vector<int> del_row;
  rep(i, W) {
    bool is_check = true;
    rep(j, H) {
      if (Board[j][i] == '#') {
        is_check = false;
        break;
      }
    }
    if (is_check == true)del_row.push_back(i);
  }
  vector<int> del_line;
  rep(i, H) {
    bool is_check = true;
    rep(j, W) {
      if (Board[i][j] == '#') {
        is_check = false;
        break;
      }
    }
    if (is_check == true)del_line.push_back(i);
  }

  rep(i, H) {
    if (find(del_line.begin(), del_line.end(), i) != del_line.end()) continue;
    rep(j, W) {
      if (find(del_row.begin(), del_row.end(), j) != del_row.end()) continue;
      cout << Board[i][j];
    }
    cout << '\n';
  }
}
