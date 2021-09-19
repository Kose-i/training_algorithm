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

  int t, n;
  cin >> t;
  vector<string> s(t);
  for (auto i = 0;i < t;++i) {
    int tmp;
    cin >> tmp;
    cin >> s[i];
  }
  for (auto i = 0;i < t;++i) {
    int ans {};
    vector<int> vec(10, 0);
    for (const char& e : s[i]) {
        ++vec[e - '0'];
    }
    for (int j = 1;j < 10;++j) {
        if (vec[j] != 0) ans += vec[j]*(j+1);
    }
    if (s[i][s[i].size()-1] != '0') --ans;
    cout << ans << '\n';
  }
}
