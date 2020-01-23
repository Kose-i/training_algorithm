#include <iostream>
#include <vector>
std::vector<std::string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

int main(int argc, char** argv) {
  std::string s;
  std::cin >> s;
  for (auto i = 0;i < day.size();++i) {
    if (s==day[i]) {
      std::cout << (7-i) << '\n';
      break;
    }
  }
}
