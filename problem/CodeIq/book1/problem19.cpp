#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  constexpr int num {20};
  std::vector<char> is_prime(num*num, 1);
  is_prime[0] = is_prime[1] = 0;
  for (auto i = 0;i < num;++i) {
    if (is_prime[i] == 0) continue;
    for (auto j = i*i;j < num*num;j += i) {
      is_prime[j] = 0;
    }
  }
  std::vector<int> prime_num;
  for (auto i = 0;i < num*num;++i) {
    if (is_prime[i] == 1) prime_num.push_back(i);
  }
  if (prime_num.size() < 6) {
    std::cout << num << " is too small\n";
    return 0;
  }
  std::vector<int> number(6, 0);
  for (auto i = 0;i < 6;++i) number[i] = prime_num[i];

  for (const auto& e : number) {
    std::cout << e << '\n';
  }
}
