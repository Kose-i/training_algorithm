#include <iostream>
#include <vector>

void swap(int& l, int& r) {
  int t = l;
  l = r;
  r = t;
}
unsigned answer(const int& N, std::vector<int>& L) {
  long long ans {};
  for (int i = N;i > 1;--i) {
    int mii1 = 0, mii2 = 1;
    for (auto j = 2;j < i;++j) {
      if (L[j] < L[mii1]) {
        mii2 = mii1;
        mii1 = j;
      } else if (L[j] < L[mii2]) {
        mii2 = j;
      }
    }
    int t = L[mii1] + L[mii2];
    ans += t;
    if (mii1 == N-1) swap(mii1, mii2);
    L[mii1] = t;
    L[mii2] = L[N-1];
  }
  return ans;
}

int main(int argc, char** argv) {
  int N {};
  std::cin >> N;
  std::vector<int> L(N);
  for (auto& e : L) {
    std::cin >> e;
  }
  std::cout << answer(N, L) << '\n';
}
