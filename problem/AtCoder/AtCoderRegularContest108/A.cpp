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

  long s, p;
  cin >> s >> p;
  std::vector<char> is_prime(1000000, 1);
  std::vector<long> primes;
  for (int i = 2;i < 1000000;++i) {
    if (is_prime[i] == 0) continue;
    primes.push_back(i);
    for (int j = i+i;j < 1000000;j += i) {
      is_prime[j] = 0;
    }
  }

  long p_cp = p;
  long t = 2;
  std::vector<long> p_primes;
  for (const auto& prime : primes) {
    while (p_cp % prime == 0) {
      p_primes.push_back(prime);
      p_cp /= prime;
    }
  }
  if (p_cp != 1) p_primes.push_back(p_cp);
  long end_bit {1<<(p_primes.size())};
  bool is_find {false};
  for (long bit = 0;bit < end_bit;++bit) {
    long ans {1};
    for (long j = 1, idx = 0;j <= bit; j <<= 1, ++idx) {
      if ((bit & j) != 0) {
        ans *= p_primes[idx];
      }
    }
    if (ans + (p/ans) == s) {
      is_find = true;
      break;
    }
  }
  if (is_find == true) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
