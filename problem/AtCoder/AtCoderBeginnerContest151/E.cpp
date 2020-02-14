#include <algorithm>
#include <iostream>
#include <vector>

constexpr int mod {1000000007};
struct mint {
  using ll = long long;
  ll x;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
constexpr long long N_max {100000};
std::vector<mint> inv_factorial(N_max+1);
std::vector<mint> factorial(N_max+1);

mint nCr(const long& n, const long& r) {
  if (n < r) return 0;
  return factorial[n]*inv_factorial[n-r]*inv_factorial[r];
}

int main(int argc, char** argv) {
  int N, K;
  std::cin >> N >> K;
  std::vector<long long> A(N);
  for (auto i = 0;i < N;++i) std::cin >> A[i];
  std::sort(A.begin(), A.end()); // A[0] = smallest, A[N-1] = biggest
  factorial[0].x = 1;
  for (long long i = 1;i <= N;++i) {
    factorial[i] = factorial[i-1]*i;
  }
  for (long long i = 0;i <= N;++i) {
    inv_factorial[i] = factorial[i].inv();
  }
  mint answer {};
  for (long long i = N-1;i >= 0;--i) {
    mint tmp = A[i];
    answer += tmp*nCr(i, K-1);
  }
//  std::cout << answer.x << '\n';
  for (long long i = 0;i < N;++i) {
    mint tmp = A[i];
    answer -= tmp*nCr(N-i-1, K-1);
  }
  std::cout << answer.x << '\n';
}
