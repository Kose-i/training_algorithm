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
bool is_solve(const int& length, vector<ull> a, const int& times) {
  int cnt {};
  for (const auto& e : a) {
    if (e <= length) break;
    cnt += e/length;
  }
  return (cnt<=times);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ull n, k;
  cin >> n >> k;
  vector<ull> a(n);
  rep(i, n) cin >> a[i];

  std::sort(a.rbegin(), a.rend());

  ull left {1};
  ull right {a[0]};

  for (ull mid = (left+right)/2;right>=left+2;) {
    mid = (left+right)/2;
    if (is_solve(mid, a, k)) {
      right = mid;
    } else {
      left = mid;
    }
    //cout << left << ' ' << right << '\n';
  }
  if (is_solve(left, a, k)) {
    std::cout << left << '\n';
  } else if (is_solve(right, a, k)) {
    std::cout << right << '\n';
  }
}
