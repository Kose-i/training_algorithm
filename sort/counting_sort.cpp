#include <iostream>
#include <vector>

void print_vec(const std::vector<int>& a) {
  for (const auto& e : a) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
namespace Kosei {
  std::vector<int> counting_sort(const std::vector<int>& a) {
    std::vector<int> count_vec(11, 0);//0 ~ 10
    for (const auto& e : a) ++count_vec[e];

    std::vector<int> ans;

    for (auto i = 0;i < count_vec.size();++i) {
      for (auto j = 0;j < count_vec[i];++j) ans.push_back(i);
    }
    return ans;
  }
}

int main(int argc, char** argv) {
  //num is all 0~10 int type

  std::vector<int> target{3,2,4,5,3,7,1};
  print_vec(target);
  std::vector<int> answer = Kosei::counting_sort(target);
  print_vec(answer);
}
