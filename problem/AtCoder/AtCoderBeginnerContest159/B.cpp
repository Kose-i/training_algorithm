#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}
bool f(string S) {
  string T(S.rbegin(), S.rend());
  if (S == T) return false;
  return true;
}

int main() {
  std::string S;
  cin >> S;
  if (f(S)) {
    cout << "No\n";
    return 0;
  }
  int N = S.size();
  string S_2(S.begin(), S.begin() + ((N-1)/2));
  if (f(S_2)) {
    cout << "No\n";
    return 0;
  }
  string S_3(S.begin() + ((N+3)/2) - 1, S.end());
  if (f(S_3)) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
}
