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
  int N;
  cin >> N;
  vector<ull> A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());

  bool is_find = false;
  rep(i, N) {
    if (A[i] % A[0] != 0) {
      is_find = true;
      break;
    }
  }
  if (is_find == false) {
    cout << A[0] << '\n';
    return 0;
  }

  constexpr ull sqrt_max_A {40000};
  vector<char> prime(sqrt_max_A+1, 1);
  prime[0] = prime[1] = 0;
  srep(i,2,sqrt_max_A+1) {
    if (prime[i] == 1) {
      for (auto j = i+i;j < sqrt_max_A+1;j += i) prime[j] = 0;
    }
  }
  vector<ull> primes;
  rep(i, sqrt_max_A+1) {
    if (prime[i] == 1) {
      primes.push_back(i);
    }
  }

  int primes_size = primes.size();
  ull answer {1};
  for (auto i = 0;i < primes_size;++i) {
    if (A[0] % primes[i] == 0) {
      rep(i, N) {
        if (A[i] % primes[i] != 0) {
          is_find = true;
          break;
        }
        A[i] /= primes[i];
      }
      if (is_find == false) answer *= primes[i];
      is_find = false;
    }
  }
  cout << answer << '\n';
}
