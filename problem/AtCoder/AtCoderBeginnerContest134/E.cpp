#include <algorithm>
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

template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];

  vector<ll> b;
  int b_size {};
  int j {};
  rep(i, N) {
    for (j = 0;j < b_size;++j) {
      if (b[j] < a[i]) break;
    }
    if (j == b_size) {
      b.push_back(a[i]);
      ++b_size;
    } else {
      b[j] = a[i];
    }
  }
  cout << b_size << '\n';
}
