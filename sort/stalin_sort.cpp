#include <iostream>
#include <vector>

namespace kosei{
  void sort(std::vector<int>& a) {
    std::vector<int> b;
    if (a.size() == 0) return;
    b.push_back(a[0]);
    for (auto i = 1, j = 0; i < a.size();++i) {
      if (a[j] < a[i]) {
        b.push_back(i);
        ++j;
      }
    }
    a = b;
  }
};

int main(int argc, char** argv) {
  std::vector<int> target{3,2,4,5,3,7,1};
  kosei::sort(target);
  for(const int& e : target) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
  return 0;
}
