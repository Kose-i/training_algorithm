#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string s;
  std::cin >> s;
  std::cout  << std::count(s.begin(), s.end(), '1') << '\n';
}
