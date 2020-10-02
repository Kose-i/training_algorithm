#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::vector<int> data {10, 12, 21, 213, 1231, 1};
  std::sort(data.begin(), data.end());

  for (const auto& e : data) {
    std::cout << e << ' ';
  }
  std::cout << '\n';

  int target_number {12};
  auto it = std::lower_bound(data.begin(), data.end(), target_number);
  int idx = std::distance(data.begin(), it);
  std::cout << target_number << ':' << idx << '\n';
}
