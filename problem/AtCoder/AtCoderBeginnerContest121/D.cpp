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

vector<ull> f(const ull& A) {
  vector<ull> answer(41, 0);
  ull box {0};
  for (ull i = 0;i < 41;++i) {
    //answer[i] = (A / box)*(box/2);
    answer[i] = (A>>(i+1))*(box>>1);

    box <<= 1;
    box += 1;
    ll tmp = A & box;
    tmp -= (box>>1);
    answer[i] += tmp;
  }
  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ull A, B;
  ////
  //cin >> A;
  //auto tmp = f(A);
  //return 0;
  ////
  cin >> A >> B;
  if (A==0 || B==0) {
    cout << B << '\n';
    return 0;
  }

  vector<ull> answer1 = f(B);
  vector<ull> answer2 = f(A-1);
  ull answer {};
  drep(i, 41) {
  //drep(i, 10) {
    answer <<= 1;
    ll tmp = answer1[i] - answer2[i];
    if (tmp % 2 == 1) answer += 1;
  }
  cout << answer << '\n';
}
