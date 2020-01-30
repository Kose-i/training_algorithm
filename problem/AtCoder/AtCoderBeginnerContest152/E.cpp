#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

constexpr int max_number{1000000};

struct Pair{
  int num;
  int cnt;
};

std::vector<int> get_prime_box() {
  std::bitset<max_number+1> prime;
  prime.flip();
  prime[0] = prime[1] = 0;
  for (auto i = 2;i <= max_number;++i) {
    if (prime[i] == 1) {
      for (auto j = i+i;j <= max_number;j += i) {
        prime[j] = 0;
      }
    }
  }
  std::vector<int> vec_box;
  for (auto i = 2;i <= max_number;++i) {
    if (prime[i] == 1) vec_box.push_back(i);
  }
  return vec_box;
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<long long> A(N);
  for (auto& e : A) std::cin >> e;
  std::vector<long long> A_cp = A;
  std::vector<int> prime_box = get_prime_box();

  std::vector<std::vector<Pair>> prime_factor(N, std::vector<Pair>());
  for (auto i = 0;i < N;++i) {
    for (auto& prime : prime_box) {
      if (A_cp[i] % prime == 0) {
        Pair k{prime, 0};
        while (A_cp[i] % prime == 0) {
          A_cp[i] /= prime;
          ++k.cnt;
        }
        prime_factor[i].push_back(k);
      }
    }
  }

  std::vector<Pair> max_prime_factor;
  for (const auto& e : prime_factor) {
    for (const auto& f : e) {
      bool is_find = false;
      for (auto& c : max_prime_factor) {
        if (c.num == f.num) {
          c.cnt = std::max(c.cnt, f.cnt);
          is_find = true;
        }
      }
      if (is_find == false) {
        max_prime_factor.push_back(f);
      }
    }
  }
  unsigned long long L {1};
  constexpr unsigned long long mod_target{1000000007};
  for (const auto& e : max_prime_factor) {
    int k {e.cnt};
    while (k > 0) {
      L *= e.num;
      --k;
    }
  }
  unsigned long long sum {};
  for (const auto& e : A) {
    sum += (L/e)%mod_target;
    sum %= mod_target;
  }
  std::cout << sum << '\n';
}
