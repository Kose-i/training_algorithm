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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  vector<char> S(10);
  rep(i, 10) cin >> S[i];
  int y {};
  rep(i, 4) {
    y *= 10;
    y += (S[i] - '0');
  }
  if (y < 2019) {
    cout << "Heisei\n";
    return 0;
  } else if (y == 2019) {
    int m {};
    srep(j, 5, 7) {
      m *= 10;
      m += (S[j] - '0');
    }
    if (m < 4) {
      cout << "Heisei\n";
      return 0;
    } else if (m == 4) {
      int d {};
      srep(k, 8, 10) {
        d *= 10;
        d += (S[k] - '0');
      }
      if (d <= 30) {
        cout << "Heisei\n";
        return 0;
      }
    }
  }
  cout << "TBD\n";
}
