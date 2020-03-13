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
  ll N_keta {};
  for (ll n = N;n != 0;n/=10) {
    ++N_keta;
  }

  ll answer {};
  if (N_keta % 2 == 1) {
    answer += N - std::pow(10, N_keta-1) + 1;
    --N_keta;
  }
  --N_keta;
  for (ll num = 1;N_keta >= 0;num *= 10) {
    if (N_keta %2==1) {
      answer -= num;
    } else {
      answer += num;
    }
    --N_keta;
  }
  cout << answer << '\n';
}
