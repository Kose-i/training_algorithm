#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

bool detect_ten(const std::string& s) {
  std::vector<char> ten(10, 0);
  for (const auto& e : s) {
    if (e != '.') ten[e-'0'] = 1;
  }
  for (const auto& e : ten) {
    if (e == 0) return false;
  }
  return true;
}
bool detect_comma_ten(const std::string& s) {
  std::vector<char> ten(10, 0);
  bool comma {false};
  for (const auto& e : s) {
    if (comma == true && e != '.') ten[e-'0'] = 1;
    if (e != '.') comma = true;
  }
  for (const auto& e : ten) {
    if (e == 0) return false;
  }
  return true;
}

int main(int argc, char** argv) {
  constexpr int d = std::numeric_limits<double>::max_digits10;

  bool first  {false};
  bool second {false};

  for (int num {2};num < 2000;++num) {
    double t = std::sqrt(num);
    std::stringstream ss;
    ss << std::setprecision(10) << t;
    std::string s = ss.str();
    if (!first && detect_ten(s)) {
      std::cout << num << ' ' << s << '\n';
      first = true;
    }
    ss.str("");
    ss.clear(std::stringstream::goodbit);
    ss << std::setprecision(11) << t;
    s = ss.str();
    if (!second && detect_comma_ten(s)) {
      std::cout << num << ' ' << s << '\n';
      second = true;
    }
  }
}
