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
void mins(T& x, T&& y) {
  x=std::min(x,y);
}

void display_bit(const int& t) {
  for (int c = 1;c > 0;c<<=1) {
    if (t & c) cout << '1';
    else cout << '0';
  }
  cout << '\n';
}
int cnt_bit(const int& t) {
  int cnt {};
  for (int c = 1;c > 0;c<<=1) {
    if (t & c) ++cnt;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  int mask {};
  rep(i, N) {
    mask += (1<<i);
  }
  vector<int> board(M, 0);
  rep(i, M) {
    int k;
    cin >> k;
    rep(j, k) {
      int tmp;
      cin >> tmp;
      board[i] += 1<<(tmp-1);
    }
  }
  vector<int> answer(M, 0);
  rep(i, M) cin >> answer[i];

  int rep_cnt {1<<(N)};

  int cnt_answer {};
  rep(i, rep_cnt) {
    int made_answer {};
    for (int j=0;j<N;++j) {
      if ((1<<j)&i) made_answer += 1<<j;
    }
    bool is_ok = true;
    rep(i, M) {
      if (cnt_bit(made_answer&board[i])%2 != answer[i]) {
        is_ok = false;
        break;
      }
    }
    if (is_ok == true) ++cnt_answer;
  }
  cout << cnt_answer << '\n';
}
