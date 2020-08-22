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

struct Node {
  int warp_cnt = -1;
  vector<int> one_pass;
  vector<int> two_pass;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;
  cin >> h >> w;
  int ch, cw, dh, dw;
  cin >> ch >> cw >> dh >> dw;
  ++ch; ++cw; ++dh; ++dw;
  vector<vector<char>> s(h+4, vector<char>(w+4, '#'));
  rep(i, h) rep(j, w) cin >> s[i+2][j+2];

  int start_idx = (w+4)*ch + cw+2;
  int end_idx = (w+4)*dh + dw+2;

  vector<Node> dp((h+4)*(w+4));

  rep(i, h+4) {
    rep(j, w+4) {
      if (s[i][j]=='.') {
        for (auto y_diff=-2;y_diff<3;++y_diff) {
          for (auto x_diff=-2;x_diff<3;++x_diff) {
            if (abs(x_diff)+abs(y_diff)==0) {
              continue;
            } else if (abs(x_diff)+abs(y_diff)==1) {
              if (s[i+y_diff][j+x_diff]=='.')dp[(w+4)*i+j].one_pass.push_back((i+y_diff)*(w+4)+j+x_diff);
            } else {
              if (s[i+y_diff][j+x_diff]=='.')dp[(w+4)*i+j].two_pass.push_back((i+y_diff)*(w+4)+j+x_diff);
            }
          }
        }
      }
    }
  }

  dp[start_idx].warp_cnt = 0;
  int loop_cnt = (w+4)*(h+4);
  for (bool is_update=true;is_update==true;) {
    is_update = false;
    rep(i, loop_cnt) {
      if (dp[i].warp_cnt!=-1) {
        for (auto& e : dp[i].one_pass) 
          if (dp[e].warp_cnt==-1 || dp[e].warp_cnt>dp[i].warp_cnt) {
            dp[e].warp_cnt = dp[i].warp_cnt;
            is_update = true;
          }
        for (auto& e : dp[i].two_pass) {
          if (dp[e].warp_cnt==-1 || dp[e].warp_cnt>dp[i].warp_cnt+1) {
            dp[e].warp_cnt = dp[i].warp_cnt+1;
            is_update = true;
          }
        }
      }
    }
  }
  cout << dp[end_idx].warp_cnt << '\n';

}
