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

bool is_first(const string& S) {
  return S[0]=='A';
}
bool is_second(const string& S) {
  int S_size = S.size();
  srep(i,2,S_size-2) {
    if (S[i] == 'C') return true;
  }
  return false;
}
bool is_third(const string& S) {
  bool is_A_find = false;
  bool is_C_find = false;
  int S_size = S.size();
  rep(i, S_size) {
    if ('a' <= S[i] && S[i] <= 'z') {
    } else if (S[i] == 'A' && is_A_find==false) {
      is_A_find = true;
    } else if (S[i] == 'C' && is_C_find == false) {
      is_C_find = true;
    } else {
      return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string S;
  cin >> S;
  if (is_first(S) && is_second(S) && is_third(S)) {
    cout << "AC\n";
  } else {
    cout << "WA\n";
  }
}
