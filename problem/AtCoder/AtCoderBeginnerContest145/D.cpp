#include <iostream>
#include <vector>

constexpr long long mod_target{1000000007};

unsigned long long answer(const unsigned long long& N, const unsigned long long& r) {
  unsigned long long ans {1};
  unsigned long long div {1};
  for (unsigned int i = 1;i <= r;++i) {
    ans *= (N-i+1);
    div *= i;
    if (ans % div == 0) {
      ans /= div;
      div = 1;
    }
  }
  return (ans/div)%mod_target;
}
constexpr long long min(long long a, long long b) {
  return (a<b)?a:b;
}

long long abs(long long a) {
  return (0<a)?a:-a;
}
int main(int argc, char** argv) {
  long long X, Y;
  std::cin >> X >> Y;
  long long X_Y_Sum {X+Y};
  if (X_Y_Sum % 3 != 0) {
    std::cout << "0\n";
    return 0;
  } else if (X == 0 || Y == 0) {
    std::cout << "1\n";
    return 0;
  }
  unsigned long long n_all  = (X+Y)/3;
  unsigned long long n_left = min(X, Y) - n_all;
  std::cout << "nCr(" << n_all << "," << n_left << ")\n";
  std::cout << answer(n_all, n_left) << '\n';
}
