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
  constexpr int mod_target {2019};
  ull L, R;
  cin >> L >> R;
  if (R - L > 2019) {
    cout << '0' << '\n';
  } else {
    int minest {2019};
    int L_mod = L % mod_target;
    int LR_size = R - L; // <= 2019
    for (int i = 0;i < LR_size;++i) {
      for (int j = i+1;j <= LR_size;++j) {
        int tmp = ((L_mod+i)*(L_mod+j))%mod_target;
        mins(minest, tmp);
      }
    }
    cout << minest << '\n';
  }
}
