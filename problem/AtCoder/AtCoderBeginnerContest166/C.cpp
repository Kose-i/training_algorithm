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

using P = std::pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  vector<P> X(M);
  rep(i, M) cin >> X[i].first >> X[i].second;
  vector<char> is_good(N, 1);
  rep(i, M) {
    if (H[X[i].first - 1] < H[X[i].second-1]) {
      is_good[X[i].first-1] = 0;
    } else if (H[X[i].first-1] == H[X[i].second-1]){
      is_good[X[i].first-1] = 0;
      is_good[X[i].second-1] = 0;
    } else {
      is_good[X[i].second-1] = 0;
    }
  }

  int answer {};
  rep(i, N) {
    if (is_good[i] == 1) ++answer;
  }
  cout << answer << '\n';
}
