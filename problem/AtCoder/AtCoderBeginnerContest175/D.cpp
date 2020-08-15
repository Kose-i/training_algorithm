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

struct Loop{
  ll score_one_turn;
  int loop_cnt;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ull n, K;
  cin >> n >> K;
  vector<int> P(n);
  rep(i, n) cin >> P[i];
  rep(i, n) --P[i];
  vector<ll> C(n);
  rep(i,n) cin >> C[i];
  
  vector<Loop> loop_turn;
  vector<int>  is_loop(n,-1);

  vector<ll> ans(n, 0);

  rep(i,n) {
    int now_pos {i};
    ll  score {};
    vector<int> vector_index;
    for (auto k = 0;k < K;++k) {
      if (is_loop[now_pos] == -1) {
        score += C[now_pos];
        now_pos = P[now_pos];
        if (std::find(vector_index.begin(), vector_index.end(), now_pos) != vector_index.end()) {
          Loop tmp;
          ll score_one_turn_tmp {};
          int loop_cnt_tmp {};
          for (auto tmp_pos = now_pos;tmp_pos != now_pos;) {
            score_one_turn_tmp += C[tmp_pos];
            ++loop_cnt_tmp;
            tmp_pos = P[tmp_pos];
            is_loop[tmp_pos] = is_loop.size();
          }
          tmp.score_one_turn = score_one_turn_tmp;
          tmp.loop_cnt = loop_cnt_tmp;
          loop_turn.push_back(tmp);
        } else {
          vector_index.push_back(now_pos);
        }
      } else {
        Loop tmp = loop_turn[is_loop[now_pos]];
        int pri_cnt = (K-k)%tmp.loop_cnt;
        score += ((K-k)/tmp.loop_cnt)*tmp.score_one_turn;
        for (auto pri = 0;pri < pri_cnt;++pri) {
          score += C[now_pos];
          now_pos = P[now_pos];
        }
      }
    }
    ans[i] = score;
  }

  ll max_ans {ans[0]};
  rep(i, n) {
    maxs(max_ans, ans[i]);
  }
  std::cout << max_ans << '\n';
}
