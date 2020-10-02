#include <iostream>
#include <vector>

namespace kosei{
  void sort(std::vector<int>& a) {
    int h {4};
    while (h > 0) {
      for (auto i = 0;i < a.size();++i) {
        auto j = i;
        auto tmp = a[i];
        while ((j >= h) && (a[j-h]>tmp)) {
          a[j] = a[j-h];
          j = j - h;
        }
        a[j] = tmp;
      }
      if (h/2 != 0) {
        h = h/2;
      } else if (h == 1) {
        h = 0;
      } else {
        h = 1;
      }
    }
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
