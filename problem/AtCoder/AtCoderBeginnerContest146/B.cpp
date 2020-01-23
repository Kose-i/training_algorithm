#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

char shift(const char& t, int n) {
//  'A' => 65 => 0
//  'Z' => 90 => 25
  int c = (t - 65 + n)%26 + 65;
  return static_cast<char>(c);
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::string s;
  std::cin >> s;
  std::for_each(s.begin(), s.end(), [=](auto& e){e = shift(e, N);});
  std::cout << s << '\n';
}
