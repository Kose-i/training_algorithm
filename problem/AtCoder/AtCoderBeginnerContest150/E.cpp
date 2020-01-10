#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

constexpr unsigned long long prim_mod{1000000007};

int main(int argc, char** argv) {
  unsigned long long N; std::cin >> N;
  std::vector<unsigned long long> C(N);
  for (auto& e : C) std::cin >> e;
  std::sort(C.begin(), C.end(), std::greater<unsigned long long>());
  for (auto& e : C) std::cout << e << ' ';
  unsigned long long sum_C {};
  for (auto i = 0;i < N;++i) sum_C += C[i]*(i+1);
  for (auto i = 0;i < N;++i) {
    sum_C += C[i]*std::pow(3, i)*(1<<(N-i-1));
  }
  //sum_C <<= N;
  std::cout << sum_C % prim_mod << '\n';
}
