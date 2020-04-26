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

bool check(const vector<string>& W, const int& N) {
  int len = W[0].size();
  char c = W[0][len-1];
  srep(i, 1, N) {
    if (c != W[i][0]) {
      return false;
    }
    len = W[i].size();
    c = W[i][len-1];
  }
  vector<string> W_cp = W;
  std::sort(W_cp.begin(), W_cp.end());
  srep(i, 1, N) {
    if (W_cp[i-1] == W_cp[i]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  vector<string> W(N);
  rep(i, N) cin >> W[i];
  if (check(W, N)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
