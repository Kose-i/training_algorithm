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
//  ull MAX_ull{1000000000000000};
//  cout << MAX_ull << '\n';
  ull N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;
  ull max_time {N/A+((N%A!=0)?1:0)};
  maxs(max_time, N/B+((N%B!=0)?1:0) );
  maxs(max_time, N/C+((N%C!=0)?1:0) );
  maxs(max_time, N/D+((N%D!=0)?1:0) );
  maxs(max_time, N/E+((N%E!=0)?1:0) );
  cout << max_time + 4 << '\n';
}
