#include <iostream>
#include <vector>
#include <utility>

constexpr unsigned long long mod {998244353};
using P = std::pair<unsigned long long, unsigned long long>;

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<P> V(N-1);
  for (auto& e : V) std::cin >> e.first >> e.second;
  unsigned long long p = N*(N-1)/2;
  unsigned long long S {};
  for (const auto& e : V) {
    S += e.first + e.second;
  }
  std::cout << (S%mod) *(p%mod) %mod << '\n';
}
