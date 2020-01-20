#include <iostream>
#include <vector>
#include <bitset>

//constexpr int Max_num {1000000};
constexpr int Max_num {10};
constexpr int mod_target {1000000007};
std::vector<int> prime_num() {
  std::bitset<Max_num+1> prime;
  for (auto i = 2;i <= Max_num;++i) {
    prime[i] = 1;
  }
  for (auto i = 2;i < Max_num/2;++i) {
    if (prime[i] == 0) continue;
    for (auto j = 2;i*j <= Max_num;++j) {
      prime[i*j] = 0;
    }
  }
  std::vector<int> prime_box;
  for (auto i = 2;i <= Max_num;++i) {
    if (prime[i] == 1) prime_box.push_back(i);
  }
  return prime_box;
}
constexpr int max(int a, int b) {
  return (a>b)?a:b;
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (auto& e : A) std::cin >> e;
  std::vector<int> prime = prime_num();
  int prime_box_size = prime.size();
  std::vector<std::vector<int>> A_prime(N, std::vector<int>(prime_box_size, 0));
  for (auto i = 0;i < N;++i) {
    for (auto j = 0;j < prime_box_size;++j) {
      while (A[i]%prime[j] == 0) {
        ++A_prime[i][j];
        A[i] /= prime[j];
      }
      if (A[i] == 1) break;
    }
  }
  for (auto& e : prime) {
    e %= mod_target;
  }
  std::vector<int> max_A_prime(prime_box_size, 0);
  for (auto i = 0;i < prime_box_size;++i) {
    for (auto j = 0;j < N;++j) {
      max_A_prime[i] = max(max_A_prime[i], A_prime[j][i]);
    }
  }
  unsigned long sum {};
  for (auto i = 0;i < N;++i) {
    unsigned long tmp_sum {1};
    for (auto j = 0;j < prime_box_size;++j) {
      for (int k = max_A_prime[j] - A_prime[i][j];k > 0;--k) {
        tmp_sum *= prime[j];
        tmp_sum %= mod_target;
      }
    }
    sum += tmp_sum;
    sum %= mod_target;
  }
  std::cout << sum << '\n';
}
