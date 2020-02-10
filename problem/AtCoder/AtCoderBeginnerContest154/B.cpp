#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string S;
  std::cin >> S;
  for (const auto& e : S) {
    std::cout << 'x';
  }
  std::cout << '\n';
}
