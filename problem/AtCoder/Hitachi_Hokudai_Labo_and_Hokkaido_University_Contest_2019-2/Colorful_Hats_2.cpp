#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int a;
  std::cin >> a;
  std::vector<int> number(a, 0);
  for (auto& e : number) {
    std::cin >> e;
  }
  std::vector<int> num_count(a, 0);//aと言われた回数
  unsigned long combination {1};
  for (const auto& e : number) {
    if (e == 0) {
      if (num_count[0] == 0) combination *= 3;
      else if (num_count[0] == 1) combination *= 2;
      ++num_count[e];
    } else {
      if (num_count[e-1] - num_count[e] == 1) {
        ++num_count[e];
      } else if (num_count[e-1] - num_count[e] == 2) {
        ++num_count[e];
        combination*=2;
      } else if (num_count[e-1] - num_count[e] == 3) {
        ++num_count[e];
        combination*=3;
      }
    }
  }
  const unsigned mod_trainer {1000000007};
  std::cout << (combination % mod_trainer) << '\n';
}
