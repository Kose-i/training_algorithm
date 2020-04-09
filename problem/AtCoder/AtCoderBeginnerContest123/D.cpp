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
  ull X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<ull> A(X);
  vector<ull> B(Y);
  vector<ull> C(Z);
  rep(i, X) {cin >> A[i];}
  rep(i, Y) {cin >> B[i];}
  rep(i, Z) {cin >> C[i];}

  std::sort(A.rbegin(), A.rend());
  std::sort(B.rbegin(), B.rend());
  std::sort(C.rbegin(), C.rend());

  vector<ull> Answer(K, 0);
  rep(i, X) {
    if (A[i] + B[0] + C[0] < Answer[K-1]) break;
    rep(j, Y) {
      if (A[i] + B[j] + C[0] < Answer[K-1]) break;
      rep(k, Z) {
        if (A[i] + B[j] + C[k] < Answer[K-1]) break;
        int left = 0;
        int right = K-1;
        ull tmp =  A[i] + B[j] + C[k];
        while (right - left > 1) {
          int mid = (left + right)/2;
          if (tmp < Answer[mid]) left = mid;
          else right = mid;
        }
        if (tmp > Answer[left]) right = left;
        srep(i, right, K) {
          ull t = tmp;
          tmp = Answer[i];
          Answer[i] = t;
        }
      }
    }
  }

  rep(i, K) {
    cout << Answer[i] << '\n';
  }
}
