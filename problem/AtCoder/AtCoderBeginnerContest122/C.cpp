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
using P = std::pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<P> Query(Q);
  rep(i, Q) cin >> Query[i].first >> Query[i].second;
  vector<int> cnt_answer(N+1, 0);
  srep(i, 1, N) {
    if (S[i] == 'C' && S[i-1] == 'A') {
      cnt_answer[i] = cnt_answer[i-1]+1;
    } else {
      cnt_answer[i] = cnt_answer[i-1];
    }
  }
  rep(i, Q) {
    cout << cnt_answer[Query[i].second-1] - cnt_answer[Query[i].first-1] << '\n';
  }
}
