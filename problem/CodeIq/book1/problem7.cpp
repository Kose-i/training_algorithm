#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::string to_double(int t) {
  std::string s{};
  while (t != 0) {
    if (t % 2 == 0) s += '0';
    else s += '1';
    t /= 2;
  }
  std::reverse(s.begin(), s.end());
  return s;
}
int main(int argc, char** argv) {
  for (int year = 1964;year <= 2020;++year) {
    for (int month = 1;month <= 12;++month) {
      for (int day = 1;day <= 31;++day) {
        int p = year*10000 + month*100 + day;
        std::string s = to_double(p);
        //std::cout << p << '\n';
        //std::cout << s << '\n';
        std::string t = s;
        std::reverse(t.begin(), t.end());
        if (t == s) std::cout << p << '\n';
      }
    }
  }
}
