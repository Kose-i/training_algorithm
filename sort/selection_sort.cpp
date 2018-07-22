#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using Point = std::pair<int,int>;
void swap(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}
namespace kosei{
  void sort(std::vector<int>& a) {
    for(int i {};i < a.size();++i) {
      Point min;
      min.second = std::numeric_limits<int>::max();
      for(int j = i;j < a.size();++j) {
        if(min.second > a[j]) {
          min.first = j;
          min.second = a[j];
        }
      }
      swap(a[i],a[min.first]);
    }
  }
};
int main(int argc, char** argv)
{
  std::vector<int> target{3,2,4,5,3,7,1};
  kosei::sort(target);
  for(const auto e : target)
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
