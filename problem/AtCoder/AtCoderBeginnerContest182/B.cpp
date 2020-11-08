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

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  std::vector<char> is_prime(1000+1, 1);
  is_prime[0] = is_prime[1] = 0;
  
  for (auto i = 2;i < 1000+1;++i) {
    if (is_prime[i] == 0) continue;
    for (auto j = i+i;j < 1000+1;j += i) {
      is_prime[j] = 0;
    }
  }
  
  std::vector<int> prime;
  for (auto i = 0;i < 1000+1;++i) {
    if (is_prime[i] == 1) prime.push_back(i);
  }

  int max_gcd_val {};
  int max_gcd_cnt {};

  for (const auto& e : prime) {
    int cnt {};
    for (const auto& num : a) {
      if (num % e == 0) ++cnt;
    }
    if (cnt > max_gcd_cnt) {
      max_gcd_cnt = cnt;
      max_gcd_val = e;
    }
  }
  cout << max_gcd_val << '\n';
}
