#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

struct Sieve{
  std::vector<long long> primes;
  Sieve(const int& n=1) {
    std::vector<char> is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (auto i = 3;i*i <= n;i += 2) { // even is not thinking
      if (is_prime[i]!=0) {
        for (auto j = i+i;j*j <= n;j += i) is_prime[j] = 0;
      }
    }
    primes.push_back(2);
    for (auto i = 3;i*i <= n;i += 2) {
      if (is_prime[i]==1) primes.push_back(i);
    }
  }
  std::vector<std::pair<long long, int>> Prime_factor(long long a) {
    std::vector<std::pair<long long, int>> prime_factor;
    for (const auto& e : primes) {
      int cnt {};
      for (;a % e == 0;) {
        a /= e;
        ++cnt;
      }
      if (cnt != 0) {
        std::pair<long long, int> tmp;
        tmp.first = e;
        tmp.second = cnt;
        prime_factor.push_back(tmp);
      }
    }
    return prime_factor;
  }

  unsigned long long prime_gcd(std::vector<long long> data) {
    std::sort(data.begin(), data.end());
    std::vector<std::pair<long long, int>> table = this->Prime_factor(data[0]);
    for (auto i = 1;i < data.size();++i) {
      for (auto& e : table) {
        int cnt {};
        for (;data[i] % e.first == 0;) {
          data[i] /= e.first;
          ++cnt;
          if (e.second < cnt) break;
        }
        if (cnt < e.second) e.second = cnt;
      }
    }
    unsigned long long ans {1};
    for (const auto& e : table) ans *= std::pow(e.first, e.second);
    return ans;
  }

};

int main(int argc, char** argv) {
  std::vector<long long> a {546,3192,1932,630,2100,4116,3906,3234,1302,1806,3528,3780,252,1008,588};
  Sieve si(a[0]);
  unsigned long long t = si.prime_gcd(a);
  std::cout << t << '\n';
}
