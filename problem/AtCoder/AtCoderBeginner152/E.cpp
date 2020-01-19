#include <iostream>
#include <vector>

constexpr unsigned mod_target {1000000007};
unsigned gcd(const unsigned& a, const unsigned& b) {
  if (b==0) return a;
  return gcd(b, a%b);
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<unsigned> A(N);
  for (auto& e : A) std::cin >> e;
  std::vector<unsigned long> B(N, 1);
  for (auto i = 0;i < N;++i) {
    unsigned tmp_cp = A[i];
    for (auto j = 0;j < i;++j) {
      B[j] *= tmp_cp;
    }
    for (auto j = i;j < N;++j) {
      if (A[j] % tmp_cp == 0) {
        A[j] /= tmp_cp;
      } else {
        unsigned gcd_kai = gcd(tmp_cp, A[j]);
        B[j] *= (tmp_cp/gcd_kai)%mod_target;
        B[j] %= mod_target;
        A[j] /= gcd_kai;
      }
    }
  }
  unsigned sum {};
  for (auto& e : B) {
    sum += (e%mod_target);
    sum %= mod_target;
  }
  std::cout << sum << '\n';
}
