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

bool is_mid(int& a, int& b, int& c) {
  if (a < b && b < c) {
    return true;
  } else if (c < b && b < a) {
    return true;
  } else {
    return false;
  }
}
int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  rep(i, N) cin >> p[i];
  int answer {};
  srep(i, 1, N-1) {
    if (is_mid(p[i-1], p[i], p[i+1])) ++answer;
  }
  cout << answer << '\n';
}
