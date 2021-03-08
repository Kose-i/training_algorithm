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

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  std::vector<int> n_vec(n);
  std::vector<int> s_vec(n);
  std::vector<int> k_vec(n);
  rep(i, n) {
    cin >> n_vec[i] >> s_vec[i] >> k_vec[i];
  }

  //rep(i, n) {
  //  if (gcd(n_vec[i], k_vec[i]) == 1) {
  //    for (ll mul_n {};;++mul_n) {
  //      if ((mul_n * n_vec[i] - s_vec[i] ) % k_vec[i] == 0) {
  //        cout << (mul_n * n_vec[i] - s_vec[i] ) / k_vec[i] << '\n';
  //        break;
  //      }
  //    }
  //  } else {
  //    cout << (((n_vec[i] - s_vec[i])%k_vec[i]==0)?(n_vec[i] - s_vec[i])/k_vec[i]:-1) << '\n';
  //  }
  //}
  rep(i, n) {
    //for (ll mul_n {1};1 <= mul_n;++mul_n) {
    int start_p = (n_vec[i] - s_vec[i] ) % k_vec[i];
    for (ll mul_n {1};1 <= mul_n;++mul_n) {
      int tmp = (mul_n * n_vec[i] - s_vec[i] ) % k_vec[i];
      if (tmp == 0) {
        cout << mul_n << '\n';
        cout << (mul_n * n_vec[i] - s_vec[i] ) / k_vec[i] << '\n';
        break;
      }
      if (mul_n != 1 && tmp == start_p) {
        cout << "-1\n";
        break;
      }
    }
  }
}
