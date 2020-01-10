#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> P(N);
  std::vector<int> Q(N);
  for (auto& e : P) std::cin >> e;
  for (auto& e : Q) std::cin >> e;

  std::vector<long long> fac(N+1, 1);
  long long sum_factorial {1};
  for (auto i = 1;i < N+1;++i) {
    sum_factorial *= i;
    fac[i] = sum_factorial;
  }

  long long P_num {};
  for (auto i = 0;i < N;++i) {
    int num {1};
    for (auto j = i+1;j < N;++j) {
      if (P[i] > P[j]) ++num;
    }
    P_num += fac[N  - i - 1]*(num - 1); 
  }
  long long Q_num {};
  for (auto i = 0;i < N;++i) {
    int num {1};
    for (auto j = i+1;j < N;++j) {
      if (Q[i] > Q[j]) ++num;
    }
    Q_num += fac[N  - i - 1]*(num - 1); 
  }
  std::cout << ((Q_num < P_num)?(P_num-Q_num):(Q_num-P_num)) << '\n';
}
