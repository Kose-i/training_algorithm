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

  string S, T;
  cin >> S >> T;
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());

  int S_size = S.size();

  vector<int> Ans_S(S_size+3, 0);
  rep(i, S_size) {
    Ans_S[i] = (S[i]-'0')*(T[0]-'0');
  }
  srep(i, 1, S_size+1) {
    Ans_S[i] += (S[i-1]-'0')*(T[1]-'0');
  }
  srep(i, 2, S_size+2) {
    Ans_S[i] += (S[i-2]-'0')*(T[3]-'0');
  }

  rep(i, S_size+2) {
    if (Ans_S[i] >= 10) {
      Ans_S[i+1] += Ans_S[i]/10;
      Ans_S[i] %= 10;
    }
  }
  reverse(Ans_S.begin(), Ans_S.end());

//  for (const auto& e : Ans_S) {
//    cout << e << '\n';
//  }
  bool is_first = true;
  rep(i, S_size+1) {
    if (is_first == true && Ans_S[i] == 0) {
    } else if (is_first == true) {
      cout << Ans_S[i];
      is_first = false;
    } else {
      cout << Ans_S[i];
    }
  }
  if (is_first == true) cout << '0';
  cout << '\n';
}
