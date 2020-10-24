#include <algorithm>
#include <iostream>
#include <vector>

//8*10^4

bool is_equal(std::string s1, std::string s2) {
  //std::sort(s1.begin(), s1.end());
  //std::sort(s2.begin(), s2.end());
  return s1==s2;
}

std::vector<std::string> split(const std::string& s, const char& t) {
  std::vector<std::string> ans;
  std::string str{};
  for (auto i =0;i < s.size();++i) {
    if (s[i] == t) {
      ans.push_back(str);
      str = "";
    } else {
      str += s[i];
    }
  }
  ans.push_back(str);
  return ans;
}

std::string eval(const std::string& s) {
  std::vector<std::string> split_s = split(s, '*');
  int num {1};
  for (const auto& e : split_s) {
    num *= stoi(e);
  }
  return std::to_string(num);
}
bool is_check(char num1, char num2, char num3, char num4) {
  const std::vector<char> op {'*', ' '};
  for (const char& a : op) {
    for (const char& b : op) {
      for (const char& c : op) {
        std::string s {};
        s += num1;
        if (a != ' ') s += a;
        s += num2;
        if (b != ' ') s += b;
        s += num3;
        if (c != ' ') s += c;
        s += num4;
        if (a == b && b == c && a == ' ') continue;
        std::string tmp_s {num4, num3, num2, num1};
        if (is_equal(eval(s), tmp_s)) std::cout << s << '\n';
      }
    }
  }
  return true;
}
int main(int argc, char** argv) {
  for (char num1 = '1';num1 <= '9';++num1) {
    for (char num2 = '0';num2 <= '9';++num2) {
      for (char num3 = '0';num3 <= '9';++num3) {
        for (char num4 = '0';num4 <= '9';++num4) {
          if (is_check(num1, num2, num3, num4)) ;//std::cout << "kd\n";
        }
      }
    }
  }
}
