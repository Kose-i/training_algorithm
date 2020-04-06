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
  std::string S;
  cin >> S;

  vector<std::string> answer{"AMBIGUOUS", "MMYY", "YYMM", "NA"};
  int answer_idx {};

  {
    int k = (S[0]-'0')*10 + (S[1]-'0');
    if (1<=k && k<=12) {
      answer_idx += 0; //****
    } else {
      answer_idx += 2; //YY**
    }
  }
  {
    int k = (S[2]-'0')*10 + (S[3]-'0');
    if (1<=k && k<=12) {
      answer_idx += 0; //****
    } else {
      answer_idx += 1; //**YY
    }
  }
  cout << answer[answer_idx] << '\n';
}
