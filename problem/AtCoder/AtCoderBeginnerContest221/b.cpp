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
  std::string s, t;
  cin >> s >> t;
  int left =-1;
  int right = -1;
  bool is_false {false};
  for (int i=0;i<s.size();++i) {
    if (left == -1 && s[i] != t[i]) {
      left = i;
    } else if (right == -1 && s[i] != t[i]) {
      right = i;
    } else if (s[i] != t[i]) {
      is_false = true;
      break;
    }
  }
  if (left == -1 && right == -1) {
    cout << "Yes\n";
  } else if ((!is_false) && left +1 == right && s[left] == t[right] && s[right] == t[left]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
