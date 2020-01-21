#include <iostream>
#include <vector>

struct Sieve{
  int n;
  std::vector<int> f, primes;
  Sieve(int n): n(n), f(n+1, 1) {
    f[0] = f[1] = 0;
    for (auto i = 2;i <= n;++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i;j <= n;j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) {return f[x] == x;}
  std::vector<int> factorList(int x) {
    std::vector<int> res;
    while (x != 0) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  std::vector<P> factor(int x) {
    std::vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    std::vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back.first == p) {
        ++res.back.second;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};
int main(int argc, char** argv) {
  int n;
  std::cin >> n;
  Sieve sieve(n);
  std::vector<int> A(n);
  for (int& e : A) std::cin >> e;
  std::vector<P> c;
  for (auto i = 0;i < n+1;++i) {
    std::vector<P> fact = sieve.factor(A[i]);
  }
}
