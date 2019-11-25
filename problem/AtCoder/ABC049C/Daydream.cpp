#include <iostream>
#include <vector>
#include <string>

std::string answer(const std::string& s) {
  std::vector<std::string> target_s{"dream","erase","eraser","dreamer"};
  auto it = s.rbegin();
  auto fit = s.rend();
  for (;it != fit;) {
    if (std::equal(target_s[0].rbegin(), target_s[0].rend(), it)) {
      it += 5;
    } else if (std::equal(target_s[1].rbegin(), target_s[1].rend(), it)) {
      it += 5;
    } else if (std::equal(target_s[2].rbegin(), target_s[2].rend(), it)) {
      it += 6;
    } else if (std::equal(target_s[3].rbegin(), target_s[3].rend(), it)) {
      it += 7;
    } else {
      return "NO";
    }
  }
  return "YES";
}

int main(int argc, char** argv) {
  std::string s;
  std::cin >> s;
  std::cout << answer(s) << '\n';
}
