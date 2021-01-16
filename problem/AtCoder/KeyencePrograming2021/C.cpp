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
vector<int> move_up(const std::vector<int>& t) {
  int size = t.size();
  vector<int> new_t(size+1, 0);
  rep(i,size) {
    new_t[i+1] = t[i];
  }
  return new_t;
}
vector<int> add_vec(const std::vector<int>& a, const std::vector<int>& b) {
  int max_size = max(a.size(), b.size());
  vector<int> c(max_size, 0);
  rep(i, a.size()) c[i] += a[i];
  rep(i, b.size()) c[i] += b[i];
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w, k;
  cin >> h >> w >> k;

  vector<vector<char>> board(h, vector<char>(w, 0));
  rep(i, k) {
    int p_h, p_w;
    char c;
    cin >> p_h >> p_w >> c;
    board[p_h-1][p_w-1] = c;
  }

  vector<vector<vector<int>>> map(h, vector<vector<int>>(w));

  {
    vector<int> tmp;
    tmp.push_back(1);//0 -> 1
    map[0][0] = tmp;
  }

  srep(i,1,h) { //down
    if (board[i-1][0] == 'R') {
      break;
    } else if (board[i-1][0] == 'X') {
      map[i][0] = move_up(map[i-1][0]);
    } else {
      map[i][0] = map[i-1][0];
    }
  }
  srep(j,1,w) {
    if (board[0][j-1] == 'D') {
      break;
    } else if (board[0][j-1] == 'X') {
      map[0][j] = move_up(map[0][j-1]);
    } else {
      map[0][j] = map[0][j-1];
    }
  }

  srep(i, 1, h) {
    srep(j, 1, w) {
      vector<int> tmp_down;
      vector<int> tmp_right;
      if (board[i-1][j] == 'D' || board[i-1][j] == 'X') {
        tmp_down = move_up(map[i-1][j]);
      } else if (board[i-1][j] != 'R') {
        tmp_down = map[i-1][j];
      }
      if (board[i][j-1] == 'R' || board[i][j-1] == 'X') {
        tmp_right = move_up(map[i][j-1]);
      } else if (board[i][j-1] != 'D') {
        tmp_right = map[i][j-1];
      }
      map[i][j] = add_vec(tmp_right , tmp_down);
    }
  }

  int hw_k = h*w - k;
  cout << hw_k << '\n';

  for (int i = 0;i < map[h-1][w-1].size();++i) {
    cout << map[h-1][w-1][i]*std::pow(3, h*w-hw_k+i-1) << ',';
  }

  ll ans {};
  cout << ans << '\n';
}
