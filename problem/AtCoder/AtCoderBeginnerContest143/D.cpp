#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<long> L(N);
  for (auto& e : L) std::cin >> e;

  std::sort(L.begin(), L.end(), std::greater<long>());
  long long cnt {};
  for (auto i = 0;i < N;++i) {
    for (auto j = i+1;j < N;++j) {
      int k {};
      int c = L[i] - L[j];
      for (k = j+1;k < N;++k) {
        if (L[k] <= c) break;
      }
      cnt += (k-j-1);
    }
  }
  std::cout << cnt << '\n';
}
