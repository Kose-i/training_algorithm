#include <iostream>
#include <vector>
#include <algorithm>

struct Arm{
  int left, right;
};

bool cmp_Arm(Arm l, Arm r) {
  return l.right < r.right;
}
int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<Arm> P(N);
  for (auto& e : P) {
    int X, L;
    std::cin >> X >> L;
    e.left = X-L;
    e.right = X+L;
  }
  std::sort(P.begin(), P.end(), cmp_Arm);
  int num {0};
  int cnt {1};
  for (auto i = 1;i < N;++i) {
    if (P[num].right <= P[i].left) {
      ++cnt;
      num = i;
    }
  }
  std::cout << cnt << '\n';
}
