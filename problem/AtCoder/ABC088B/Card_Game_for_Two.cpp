#include <algorithm>
#include <iostream>
#include <vector>

int card_ans(const int& size, const std::vector<int>& vec) {
  auto sorted_vec = vec;
  std::sort(sorted_vec.begin(), sorted_vec.end(), std::greater<int>());
  int even_sum {};
  int odd_sum {};
  for (auto i = 0; i < size;++i) {
    if (i % 2 == 0) {
      even_sum += sorted_vec[i];
    } else {
      odd_sum += sorted_vec[i];
    }
  }
  return (even_sum - odd_sum);
}
int main(int argc, char** argv) {
  const int N {[](){int t;std::cin >> t;return t;}()};
  std::vector<int> cards;
  for (auto i = 0;i < N;++i) {
    int t;
    std::cin >> t;
    cards.push_back(t);
  }
  std::cout << card_ans(N, cards) << '\n';
}
