#include <iostream>
#include <vector>


void swap(int& a, int& b) {
  int t = std::move(a);
  a = std::move(b);
  b = std::move(t);
}
namespace kosei{
  void sort(std::vector<int>& a) {
    int search_duration = a.size() / 1.3;

    for (bool is_changed = true;search_duration > 1 || is_changed == true;) {
      is_changed = false;
      if (search_duration == 1) {
        search_duration = a.size() / 1.3;
      } else {
        --search_duration;
      }

      for (auto i = 0;i < a.size() - search_duration;++i) {
        if (a[i + search_duration] < a[i]) {
          swap(a[i], a[i + search_duration]);
          is_changed = true;
        }
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
