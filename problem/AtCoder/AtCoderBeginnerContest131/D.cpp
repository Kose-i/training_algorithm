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

struct P {
  ll a,b;
};

int main() {
  int N;
  cin >> N;
  vector<P> X(N);
  rep(i, N) cin >> X[i].a >> X[i].b;
  std::sort(X.begin(), X.end(), [](P l, P r){return l.b<r.b;});

  ll sum_now{};
  bool is_error {false};
  rep(i, N) {
    sum_now += X[i].a;
    if (X[i].b < sum_now) {
      is_error = true;
      break;
    }
  }
  if (is_error == true) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}
