#include <iostream>

long long mod_pow(long long x, long long n, long long mod) {
  if (n == 0) return 1;
  long long res = mod_pow(x*x%mod, n/2, mod);
  if (n & 1) res = res*x%mod;
  return res;
}
bool is_prime(const long long& x) {
  for (auto i = 2;i*i < x;++i) {
    if (x % i == 0) return false;
  }
  return true;
}

int main(int argc, char** argv) {
  const int n {561};
  bool is_ok = true;
  if (is_prime(n)) is_ok = false;
  for (long long x = 2;x < n && is_ok;++x) {
    if (mod_pow(x,n,n) == 0) {
      is_ok = false;
    }
  }
  if (is_ok == true) std::cout << "Yes\n";
  if (is_ok == false) std::cout << "No\n";
}
