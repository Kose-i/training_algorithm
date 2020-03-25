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

bool is_ok(const ll& t) {
  ll c = 0;
  for (c = 0;c*c < t;++c) ;
  if (c*c == t) return true;
  return false;
}
bool is_num(const vector<ll>& v1, const vector<ll>& v2, const int& D) {
  ll k {}; 
  rep(i, D) {
    k += (v1[i] - v2[i])*(v1[i] - v2[i]);
  }
  return is_ok(k);
}

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<ll>> X(N, vector<ll>(D));
  rep(i, N) rep(j, D) cin >> X[i][j];
  int answer {};
  rep(i, N) {
    srep(j,i+1,N) {
      if (is_num(X[i], X[j], D)) ++answer;
    }
  }
  cout << answer << '\n';
}
