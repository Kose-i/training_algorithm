#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

#define maxs(x,y) (x=std::max(x,y))
#define mins(x,y) (x=std::min(x,y))

int main() {
  ll N;
  cin >> N;
  vector<ll> H(N);
  rep(i,N) std::cin >> H[i];
  ll max_cnt {0};
  ll tmp_cnt {0};
  drep(i,N-1) {
    if (H[i] >= H[i+1]) {
      ++tmp_cnt;
    } else {
      maxs(max_cnt, tmp_cnt);
      tmp_cnt = 0;
    }
  }
  maxs(max_cnt, tmp_cnt);
  std::cout << max_cnt << '\n';
}
