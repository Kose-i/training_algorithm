#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF
constexpr int INTINF {10000000};

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

int make_answer(const int& H, const int& W, const int& K, const int& bits, const vector<vector<int>>& t) {
  vector<int> vec_bits;
  int c {1};
  rep(i, H) {
    if (bits & c) vec_bits.push_back(i);
    c <<= 1;
  }
  //value 0 is 0-1 split
  int S_H = vec_bits.size()+1;

  vector<vector<int>> S(S_H, vector<int>(W+1, 0)); // W+1 is 番兵
  c = 0;
  for (auto i = 0;i < H;++i) {
    rep(j, W) {
      S[c][j] += t[i][j];
      if (c < S_H-1 && vec_bits[c] == i) ++c;
    }
  }

  int answer {};
  vector<int> ans_sum(S_H, 0);
  rep(i, S_H) {
    ans_sum[i] = S[i][0];
  }
  rep(i, W) {
    rep(j, S_H) {
      if (ans_sum[j] > K) {
        return INTINF;
      } else if (ans_sum[j]+S[j][i+1] > K) {
        ++answer;
        ans_sum[j] = 0;
        rep(k, S_H) ans_sum[k] = S[k][i+1];
        break;
      } else {
        ans_sum[j] += S[j][i+1];
      }
    }
  }
  return answer;
}

constexpr int end_bit{1<<10};
int bits_cnt(const int& t, const int& H) {
  int ans {};
  int tmp {1};
  rep(i, H) {
    if (tmp & t) ++ans;
    tmp <<= 1;
  }
  return ans;
}
int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int>> Block(H, vector<int>(W));
  rep(i, H) rep(j, W) {
    char c;
    cin >> c;
    if (c == '1') Block[i][j] = 1;
    else Block[i][j] = 0;
  }
  int end = 1<<H;
  int answer {INTINF};
  for (int c = 0;c != end;++c) {
    int t = bits_cnt(c, H) + make_answer(H, W, K, c, Block);
    mins(answer , t);
  }
  cout << answer << '\n';
}
