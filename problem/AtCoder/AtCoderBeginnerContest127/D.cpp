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

struct P {
  int B;
  ll C;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<P> X(M);
  rep(i, M) cin >> X[i].B >> X[i].C;

  std::sort(A.begin(), A.end());
  std::sort(X.begin(), X.end(), [](auto& l, auto& r){return (l.C>r.C);});
  rep(i, M) {
    if (X[i].C > A[0]) {
      rep(j, X[i].B) {
        if (X[i].C < A[j]) break;
        A[j] = X[i].C;
      }
      std::sort(A.begin(), A.end());
    }
  }

  ll sum {};
  rep(i, N) {sum += A[i];}
  cout << sum << '\n';
}
