#include <iostream>
#include <vector>

const std::vector<int> coin{500, 100, 50, 10};

int convolution(int money, int cnt, const std::vector<int>& usable, int idx) {
  if (cnt > 15) return 0;
  if (idx == coin.size() && money == 0) return 1;
  if (idx == coin.size()) return 0;
  if (money < coin[idx]) return convolution(money,cnt,usable, idx+1);
  int ans {};
  for (auto i = 0;i <= usable[idx];++i) {
    if (money < coin[idx]*i) break;
    ans += convolution(money - (coin[idx]*i),cnt+i,usable, idx+1);
  }
  return ans;
}

int main(int argc, char** argv) {
  //500, 100, 50, 10
  //std::vector<int> usable{2, 10, 20, 100};
  std::vector<int> usable{2, 10, 15, 15};
  std::cout << convolution(1000, 0,usable, 0) << '\n';
}
