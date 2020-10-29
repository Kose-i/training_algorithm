#include <iostream>
#include <vector>

int main(int argc, char** argv) {

  std::vector<int> prime_num;
  std::vector<char> is_prime(101,1);
  for (auto i =2;i<=100;++i) {
    if (is_prime[i]) {
      for (auto j = i+i;j <=100;j +=i)is_prime[j] =0;
      prime_num.push_back(i);
    }
  }

  int answer {};
  for (int num = 1;num <= 100;++num) {
    int num_divisor {1};
    int num_tmp {num};
    for (const auto& e : prime_num) {
      int cnt {1};
      while (num_tmp % e == 0) {
        num_tmp /= e;
        ++cnt;
      }
      num_divisor *= cnt;
    }
    if (num_divisor %2 == 1) std::cout << num << ',';
  }

  std::cout << '\n';
}
