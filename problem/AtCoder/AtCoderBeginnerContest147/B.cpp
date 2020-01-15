#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv) {
  std::string s;
  std::cin >> s;
  int n = s.size();
  int cnt {};
  for (auto i = 0;i < n/2;++i) {
    if (s[i] != s[n-i-1]) ++cnt;
  }
  std::cout << cnt << '\n';
}
