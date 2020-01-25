#include <iostream>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  bool is_find = false;
  for (auto i = 1; i <= 9;++i) {
    if (N % i == 0) {
      int c = N/i;
      if (1 <= c && c <= 9) {
        is_find = true;
        break;
      }
    }
  }
  if (is_find == false) {
    std::cout << "No\n";
  } else {
    std::cout << "Yes\n";
  }
}
