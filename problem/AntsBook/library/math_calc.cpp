
int gcd(const int& a, const int& b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int extgcd(const int& a, const int& b, int& x, int& y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

long long mod_pow(long long x, long long n, long long mod) {
  if (n == 0) return 1;
  long long res = mod_pow(x*x % mod, n / 2, mod);
  if (n & 1) res = res * x % mod;
  return res;
}
