#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <numeric>

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
  int A, B, K;
  cin >> A >> B >> K;
  vector<int> vec(100);
  std::iota(vec.begin(), vec.end(), 1);
  rep(i, 100) {
    if (A % vec[i] == 0 && B % vec[i] == 0) {
    } else {
      vec[i] = 0;
    }
  }
  int cnt {};
  drep(i, 100) {
    cnt = i;
    if (vec[i] != 0) --K;
    if (K == 0) break;
  }
  cout << vec[cnt] << '\n';
}
