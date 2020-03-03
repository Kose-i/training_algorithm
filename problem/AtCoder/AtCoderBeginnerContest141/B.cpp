#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  bool is_odd  = true;
  bool is_even = true;
  std::string S;
  std::cin >> S;
  int S_size = S.size();
  for (auto i = 0;i < S_size;++i) {
    if (i % 2 == 0) {
      if (S[i] == 'R' || S[i] == 'U' || S[i] == 'D') {
      } else {
        is_even = false;
      }
    } else {
      if (S[i] == 'L' || S[i] == 'U' || S[i] == 'D') {
      } else {
        is_odd = false;
      }
    }
  }
  if (is_odd && is_even) std::cout << "Yes\n";
  else std::cout << "No\n";
}
