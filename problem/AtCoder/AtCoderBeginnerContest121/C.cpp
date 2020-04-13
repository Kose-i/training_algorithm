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

struct Cost {
  ull cost;
  int cnt;
};
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<Cost> A(N);
  rep(i, N) cin >> A[i].cost >> A[i].cnt;
  std::sort(A.begin(), A.end(), [](auto& l, auto& r){return l.cost<r.cost;});

  int cnt {};
  ull money {};
  rep(i, N) {
    if (cnt + A[i].cnt > M) {
      money += A[i].cost*(M-cnt);
      break;
    } else {
      cnt += A[i].cnt;
      money += A[i].cnt*A[i].cost;
    }
  }
  cout << money << '\n';
}
