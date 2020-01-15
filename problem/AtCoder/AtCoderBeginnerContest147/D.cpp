#include <iostream>
#include <vector>

constexpr unsigned long mod_p {1000000007};

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<unsigned long> vec(N);
  for (auto i = 0;i < N;++i) {
    std::cin >> vec[i];
  }
  std::vector<unsigned> one_mat(60, 0);
  for (const unsigned long& e : vec) {
    unsigned long t = e;
    for (int dimension {};dimension<60 && t!=0;++dimension) {
      if (t % 2) ++one_mat[dimension];
      t >>= 1;
    }
  }
  for (const auto& e : one_mat) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
  unsigned long t {1};
  unsigned long sum {};
  for (auto i = 0;i < 60;++i) {
    sum += t*(one_mat[i])*(N-one_mat[i])%mod_p;
    t <<= 1;
  }
  std::cout << sum%mod_p << '\n';
}
