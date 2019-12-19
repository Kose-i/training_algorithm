#include <iostream>
#include <vector>

namespace prob30{
  unsigned long answer(const int& color_size) {
    std::vector<unsigned long> pair(color_size+1, 0);
    pair[1] = 0;
    pair[2] = 1;
    for (auto i = 3;i <= color_size; ++i) {
      pair[i] = (2*i-2 + 1)* pair[i - 1] + pair[i - 2];
    }
    return pair[color_size];
  }
}

int main(int argc, char** argv) {
  const int colors {11};
  std::cout << prob30::answer(colors) << '\n';
}
