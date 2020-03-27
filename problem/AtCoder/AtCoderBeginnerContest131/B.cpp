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
constexpr int INTINF {1000000};

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
  int N, L;
  cin >> N >> L;
  int answer {};
  int minest_abs {L+1-1};
  srep(i,2,N+1) {
    int t = L+i-1;
    if (std::abs(t) < std::abs(minest_abs)) {
      answer += minest_abs;
      minest_abs = t;
    } else {
      answer += t;
    }
  }
  cout << answer << '\n';
}
