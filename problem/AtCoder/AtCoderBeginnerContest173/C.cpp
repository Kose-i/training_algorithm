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

bool is_ok(const vector<vector<char>>& Board, const int& H, const int& W, const int& K, const vector<int>& judge) {
  vector<vector<char>> B = Board;
  rep(i, W) {
    if (judge[i] == 1) {
      rep(j, H) B[j][i] = '.';
    }
  }
  srep(i, W, W+H) {
    if (judge[i] == 1) {
      rep(j, W) B[i-W][j] = '.';
    }
  }

  int p {};
  rep(i, H) {
    rep(j, W) {
      if (B[i][j] == '#') ++p;
    }
  }
  return (p==K);
}
ll answer_judge(int index, const vector<vector<char>>& Board, vector<int> judge, const int& K, const int& H, const int& W) {
  if (index == H + W) {
    return (is_ok(Board, H, W, K, judge)?1:0);
  }
  judge[index] = 0;
  ll c = answer_judge(index+1, Board, judge, K, H, W);
  judge[index] = 1;
  c   += answer_judge(index+1, Board, judge, K, H, W);
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int H, W, K;
  cin >> H >> W >> K;

  std::vector<std::vector<char>> Board(H, vector<char>(W, 0));
  rep(i, H) {
    rep(j, W) {
      cin >> Board[i][j];
    }
  }

  std::vector<int> judge(H+W, 0);
  ll answer = answer_judge(0, Board, judge, K, H, W);
  cout << answer << '\n';
}
