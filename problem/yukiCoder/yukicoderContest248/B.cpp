#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  std::unordered_map<int, int> mp;
  int color {A[0]};
  ++mp[A[0]];
  bool is_yes = true;
  bool is_split = false;
  int ans {};

  rep(i, n) {
    if (is_split == true) {
      ans = 1;
      if (A[i] != A[0]) {
        ans = -1;
        break;
      }
    } else if (A[i] != color && mp[A[i]]!=0) {
      if (A[i] == A[0]) {
        is_split = true;
        ans = 1;
      } else {
        ans = -1;
        break;
      }
    } else if (A[i] != color){
      ++mp[A[i]];
      color = A[i];
    }
  }

  cout << ans << '\n';
}
