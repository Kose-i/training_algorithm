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

int find(const int& idx, std::vector<int>& idx_to_path) {
  if (idx == idx_to_path[idx]) return idx;
  return idx_to_path[idx] = find(idx_to_path[idx], idx_to_path);
}
int main(int argc, char** argv) {
  int n;
  cin >> n;
  std::vector<char> s(n+2, '.');
  rep(i, n) {
    cin >> s[i+2];
  }
  n += 2;

  std::vector<int> idx(n);
  rep(i, n) idx[i] = i;

  int ans {n-2};

  for (int i = 2;i < n;++i) {
    int c3 = i;
    int c2 = find(c3-1, idx);
    int c1 = find(c2-1, idx);
    if (s[c1] == 'f' && s[c2] == 'o' && s[c3] == 'x') {
      idx[c3] = find(c1-1, idx);
      idx[c2] = find(idx[c3]-1, idx);
      idx[c1] = find(idx[c2]-1, idx);
      ans -= 3;
    }
  }
  std::cout << ans << '\n';
}
