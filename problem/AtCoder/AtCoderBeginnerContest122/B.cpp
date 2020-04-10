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
bool include_atgc(char& c) {
  if (c == 'A') return true;
  if (c == 'T') return true;
  if (c == 'G') return true;
  if (c == 'C') return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string S;
  cin >> S;

  int S_size = S.size();
  int answer {};
  rep(i, S_size) {
    if (!include_atgc(S[i])) continue;
    int tmp {1};
    srep(j, i+1, S_size) {
      if (!include_atgc(S[j])) break;
      ++tmp;
    }
    maxs(answer, tmp);
  }
  cout << answer << '\n';
}
