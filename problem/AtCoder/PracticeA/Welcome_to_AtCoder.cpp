#include <iostream>
#include <string>

int main(int argc, char** argv) {
  const int a {[](){int t;std::cin >> t;return t;}()};
  const int b {[](){int t;std::cin >> t;return t;}()};
  const int c {[](){int t;std::cin >> t;return t;}()};
  std::string s;
  std::cin >> s;
  std::cout << (a+b+c) << ' ' << s << '\n';
}
