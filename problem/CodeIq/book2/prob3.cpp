#include <iostream>

/*
std::vector<std::map<char, unsigned>> map{
{'I', 1}, {'V', 5}, {'X',10},
{'L', 50}, {'C', 100}, {'D', 500},
{'M', 1000}
};
*/
namespace prob3{
  unsigned roman_font_size(const unsigned& target_num) {
    if (target_num < 4) {
      return target_num;
    } else if (target_num == 4) {
      return 2;
    } else if (target_num == 5) {
      return 1;
    } else if (target_num < 9) {
      return (target_num - 4);
    } else {
      return 2;
    }
  }
  unsigned roman_size(unsigned target_num) {
    unsigned size_tmp = roman_font_size(target_num / 1000);
    target_num %= 1000;
    size_tmp += roman_font_size(target_num / 100);
    target_num %= 100;
    size_tmp += roman_font_size(target_num / 10);
    target_num %= 10;
    size_tmp += roman_font_size(target_num);
    return size_tmp;
  }
  unsigned answer() {
    unsigned ans_tmp {};
    for (auto i = 1;i < 4000;++i) {
      if (roman_size(i) == 12) {
        ++ans_tmp;
      }
    }
    return ans_tmp;
  }
}
int main(int argc, char** argv) {
  std::cout << prob3::answer() << '\n';
}
