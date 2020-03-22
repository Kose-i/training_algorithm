#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF

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

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> B = A;
  std::sort(B.begin(), B.end());

  std::map<ll, ll> answer_map;
  for (auto i = 0;i < N;++i) {
    ++answer_map[A[i]];
  }
  ll sum_cnt {};
  auto answer_map_end = answer_map.end();
  for (auto it = answer_map.begin(); it != answer_map_end;++it) {
    ll tmp = it->second;
    sum_cnt += tmp*(tmp - 1)/2;
  }
  for (auto e : A) {
    if (answer_map[e] != 1) {
      ll tmp = answer_map[e]*(answer_map[e]-1) - (answer_map[e]-1)*(answer_map[e]-2);
      cout << sum_cnt - tmp/2 << '\n';
    } else {
      cout << sum_cnt << '\n';
    }
  }
}
