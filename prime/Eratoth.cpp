#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#define MAX_SIZE 1000

std::vector<unsigned> make_prime() {
  std::bitset<MAX_SIZE> judge_prime(true);
  for(int i = 0;i < MAX_SIZE;++i) {
    judge_prime[i] = true;
  }
  unsigned check_i = std::sqrt(MAX_SIZE);
  for(unsigned i = 2;i < check_i;++i) {
    if(judge_prime[i]) {
      for(unsigned j = i * i;j <= MAX_SIZE;j += i) {
        judge_prime[j] = false;
      }
    }
  }
  std::vector<unsigned> prime;
  for(unsigned i = 2;i < MAX_SIZE;++i) {
    if(judge_prime[i])prime.push_back(i);
  }
  return prime;
}
int main(int argc, char** argv) {
  std::vector<unsigned> prime = make_prime();
  for(const auto& e : prime) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
