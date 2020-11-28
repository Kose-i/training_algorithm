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

char search(const int& k, const int& n, std::vector<std::vector<char>>& dp, const ll& idx) {
  if (dp[k][idx%n] != '.') return dp[k][idx%n];
  return dp[k][idx%n] = winner(search(k-1, n, dp, 2*idx%n), search(k-1, n, dp, (2*idx+1)%n));
}

char ans_find(const int& k, const int& n, const std::string& s) {
  std::vector<std::vector<char>> dp(k, std::vector<char>(n, '.'));
  rep(i, n) {
    dp[0][i] = s[i];
  }
  char l = search(k-1, n, dp, 0);
  char r = search(k-1, n, dp, 1);

  return winner(l, r);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  std::string s;
  cin >> s;
  s += s;
  n *= 2;

  cout << ans_find(k, n, s) << '\n';
}
