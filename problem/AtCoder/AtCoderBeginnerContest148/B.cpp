#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
  int N; std::cin >> N;
  std::string S; std::cin >> S;
  std::string T; std::cin >> T;
  std::vector<char> new_string;
  for (auto i = 0;i < N;++i) {
    new_string.push_back(S[i]);
    new_string.push_back(T[i]);
  }
  for (const auto& e : new_string) {
    std::cout << e;
  }
  std::cout << '\n';
}
