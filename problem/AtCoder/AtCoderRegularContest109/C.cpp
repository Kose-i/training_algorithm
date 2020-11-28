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

using Pair = std::pair<int, int>;

char winner(const char& l, const char& r) {
  if (l == r) return l;
  if (l == 'R' && r == 'P' || l == 'P' && r == 'R') return 'P';
  if (l == 'S' && r == 'P' || l == 'P' && r == 'S') return 'S';
  if (l == 'R' && r == 'S' || l == 'S' && r == 'R') return 'R';
  return '.';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  std::string s;
  cin >> s;
  s += s;

  std::string target_s {s};

  for (auto i = 0;i < k;++i) {
    int new_s_size {static_cast<int>(target_s.size())};
    std::string new_s{};
    for (auto j = 0;j < new_s_size;++j) {
      new_s += winner(target_s[2*j%n], target_s[(2*j + 1)%n]);
    }
    target_s = new_s;
    //std::cout << target_s << '\n';
  }
  cout << target_s[0] << '\n';
}
