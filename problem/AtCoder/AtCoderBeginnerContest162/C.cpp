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

int gcd(int a, int b) { return b?gcd(b,a%b):a;}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int K;
  cin >> K;
  vector<vector<int>> gcd_box(201, vector<int>(201, 1));
  rep(i, 201) {
    srep(j, i, 201) {
      gcd_box[i][j] = gcd(i, j);
      gcd_box[j][i] = gcd_box[i][j];
    }
  }

  ull answer {};
  srep(i,1,K+1) {
    srep(j,1,K+1) {
      int c = gcd_box[i][j];
      srep(k,1,K+1) {
        answer += gcd_box[c][k];
      }
    }
  }
  cout << answer << '\n';
}
