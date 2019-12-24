#include <iostream>
#include <vector>
#include <opencv.hpp>

int main(int argc, char** argv) {
  std::vector<std::vector<int>> map(8, std::vector<int>(8));
  for (const auto& e : map) {
    bool is_check = false;
    for (const auto& f : e) {
      if (is_check) std::cout << ' ';
      std::cout << f;
      is_check = true;
    }
    is_check = false;
  }
}
