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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  int max_prime_cnt {};
  vector<int> prime(1000+1, 1);
  prime[0] = prime[1] = 0;
  for (auto i = 0;i < 1000+1;++i) {
    if (prime[i] == 0) continue;
    for (auto j = i+i;j < 1000+1;j += i) {
      prime[j] = 0;
    }
  }
  vector<int> prime_number;
  for (auto i = 0;i < 1000+1;++i) {
    if (prime[i] == 1) prime_number.push_back(i);
  }

  vector<vector<int>> p_table(n, vector<int>(prime_number.size(), 0));
  rep(i, n) {
    rep(j, prime_number.size()) {
      if (a[i] % prime_number[j] == 0) {
        p_table[i][j] = 1;
        while (a[i] % prime_number[j] == 0) a[i]/= prime_number[j];
      }
    }
  }
  int prime_number_size = prime_number.size();

  vector<int> table(prime_number_size, 0);
  rep(i, n) {
    rep(j, prime_number_size) table[j] += p_table[i][j];
  }

  bool pair_wise {true};
  bool set_wise  {true};

  rep(i, prime_number_size) {
    if (table[i] == n) {
      pair_wise = false;
      set_wise = false;
      break;
    } else if (table[i] > 1) {
      pair_wise = false;
    }
  }
  sort(a.begin(), a.end());
  rep(i, n-1) {
    if (a[i]!= 1 && a[i]==a[i+1]) pair_wise = false;
  }
  if (a[0]!=1) {
    rep(i, n-1) {
      if (a[i]!=a[i+1]) break;
      if (i==n-2) set_wise = false;
    }
  }

  if (pair_wise == true) {
    cout << "pairwise coprime\n";
  } else if (set_wise == true) {
    cout << "setwise coprime\n";
  } else {
    cout << "not coprime\n";
  }
}
