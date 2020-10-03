#include <iostream>
#include <vector>

namespace kosei{
  void sort(std::vector<int>& a) {
    // all val is int
    int max_val {a[0]};
    int min_val {a[0]};
    for (const auto& e : a) {
      if (e > max_val) max_val = e;
      if (e < min_val) min_val = e;
    }
    std::vector<int> b(max_val - min_val + 1, 0);
    for (const auto& e : a) {
      ++b[e-min_val];
    }
    std::vector<int> a_sorted(a.size(), 0);
    int idx {};
    for (auto i = 0;i < b.size();++i) {
      int val = i+min_val;
      for (int cnt = 0;cnt < b[i];++cnt) {
        a_sorted[idx] = val;
        ++idx;
      }
    }
    a = a_sorted;
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
