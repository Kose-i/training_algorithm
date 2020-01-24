#include <iostream>
#include <string>

std::string num_to_s(int n, int d) {
  std::string s;
  s += '0' + n%d;
  while (n / d) {
    n /= d;
    s += '0' + n%d;
  }
  return s;
}

std::string reverse_num_to_s(int n, int d) {
  std::string s;
  s += '0' + n%d;
  while (n / d) {
    n /= d;
    s += '0' + n%d;
  }
  int s_size = s.size();
  std::string t;
  for (auto i = 0;i < s_size;++i) {
    t += s[s_size-1-i];
  }
  return t;
}

bool is_ok(int num) {
  return (num_to_s(num, 10) == reverse_num_to_s(num, 10) && num_to_s(num, 8) == reverse_num_to_s(num, 8) && num_to_s(num, 2) == reverse_num_to_s(num, 2));
}

int answer() {
  int num {11};
  while (num > 0) {
    if (is_ok(num)) {
      break;
    }
    ++num;
  }
  return num;
}

int main(int argc, char** argv) {
  std::cout << answer() << '\n';
}
