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

struct doublepair{
  int a, b;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ull n;
  cin >> n;
  std::vector<ull> three;
  std::vector<ull> five;
  for (ull i=3;i < n;i *=3) {
    three.push_back(i);
  }
  for (ull i=5;i < n;i *=5) {
    five.push_back(i);
  }

  bool is_find {false};
  doublepair ans;
  for (int i = 0;i < three.size();++i) {
    for (int j = 0;j < five.size();++j) {
      if (three[i] + five[j] > n) {
        break;
      } else if (three[i] + five[j] == n) {
        ans.a = i+1;
        ans.b = j+1;
        is_find = true;
        break;
      }
    }
    if (is_find == true) break;
  }
  if (is_find) cout << ans.a << ' ' << ans.b << '\n';
  else cout << -1 << '\n';
}
