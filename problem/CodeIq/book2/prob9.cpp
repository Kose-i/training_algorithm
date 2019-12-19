#include <iostream>
#include <vector>
#include <cmath>
#include <string>

namespace prob9{
  unsigned to_d(const std::string& tmp_str) {
    unsigned ans_to_d {};
    for (auto e : tmp_str) {
      ans_to_d *= 8;
      ans_to_d += e - '0';
    }
    return ans_to_d;
  }
  bool is_checked(const std::string& tmp_str) {
    unsigned sum {};
    auto ketasuu = tmp_str.size();
    for (const auto& e : tmp_str) {
      sum += std::pow(e - '0', ketasuu);
    }
    return (sum == to_d(tmp_str));
  }
  std::string to_str_hex(const unsigned& target_num) {
    std::string to_str_hex_tmp {};
    for (auto i = target_num;i != 0;i /= 8) {
      to_str_hex_tmp += (i % 8) + '0';
    }
    return std::string(to_str_hex_tmp.rbegin(), to_str_hex_tmp.rend());
  }
  std::vector<std::string> make_answer() {
    constexpr auto target_size = 8;
    std::vector<std::string> answer_tmp {};
    for (auto size_check = 0, k = 8;;++k) {
      std::string tmp_str = to_str_hex(k);
      if (is_checked(tmp_str)) {
        ++size_check;
        answer_tmp.push_back(tmp_str);
        if (size_check == target_size) break;
      }
    }
    return answer_tmp;
  }
  void answer() {
    std::vector<std::string> ans_tmp = make_answer();
    for (const auto& e: ans_tmp) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }
}
int main(int argc, char** argv) {
  prob9::answer();
}
