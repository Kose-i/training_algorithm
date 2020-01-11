#include <iostream>
#include <vector>

constexpr unsigned long mod_po{1000000007};

unsigned long factorial(const int& N, std::vector<unsigned long>& fact_map) {
  if (N == 0) return 1;
  if (fact_map[N] != 0) return fact_map[N];
  return fact_map[N] = N*factorial(N-1, fact_map);
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> X(N);
  for (auto& e : X) std::cin >> e;

  int duration_cnt {N-1};
  std::vector<int> a(duration_cnt);
  for (auto i = 0;i < duration_cnt;++i) {
    a[i] = X[i+1] - X[i];
  }
  std::vector<unsigned long> fact_map(N, 0);

  std::vector<int> multiple_cnt(N, 0);
  unsigned long ans {};
  for (auto i = 0;i < duration_cnt;++i) {
    ans += (factorial(duration_cnt - i, fact_map) + 2*(duration_cnt - i - 1))*a[i]%mod_po;
  }
  std::cout << (ans%mod_po) << '\n';
}
