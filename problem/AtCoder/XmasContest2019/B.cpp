#include <iostream>

int main(int argc, char** argv) {
  int N; std::cin >> N;
  char op; std::cin >> op;
  std::vector<int> vec(N);
  bool is_check = false;
  for (const auto& e : vec) {
    if (is_check == true) std::cout << ' ';
    std::cout << e;
    is_check = true;
  }
}
