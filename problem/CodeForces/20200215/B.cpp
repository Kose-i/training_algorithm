#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> str_box(n);
  rep(i, n) std::cin >> str_box[i];
  std::vector<std::string> str_inv_box(n);
  rep(i, n) str_inv_box[i] = std::string(str_box[i].rbegin(), str_box[i].rend());
  int mid_num = -1;
  std::vector<int> num;
  for (auto i = 0;i < n;++i) {
    auto t = std::find(str_box.begin() + i, str_box.end(), str_inv_box[i]);
    int k = t - str_box.begin();
    if (k == i) {
      mid_num = i;
      continue;
    } else if (k != n) {
      num.push_back(k);
    }
  }
  int num_size = num.size();
  int answer = 2*m*num_size;
  if (mid_num != -1) answer += m;
  std::cout << answer << '\n';
  for (auto i = num_size-1;i >= 0;--i) {
    std::cout << str_inv_box[num[i]];
  }
  if (mid_num != -1) std::cout << str_box[mid_num];
  for (auto i = 0;i < num_size;++i) {
    std::cout << str_box[num[i]];
  }
  std::cout << '\n';
}
