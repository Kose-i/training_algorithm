#include <iostream>
#include <vector>
#include <map>

constexpr int min(int a, int b) {
  return (a<b)?a:b;
}
int answer(const int& P, const std::vector<int>& a) {
  std::map<int, int> count;
  for (const auto& e : a) {
    if (count.find(e) == count.end()) count.insert(std::make_pair(e, 0));
  }
  int n = count.size();

  int s = 0, t = 0, num = 0;
  int res = P;
  for (;;) {
    while (t < P && num < n) {
      if (count[a[t++]]++ == 0) ++num;
    }
    if (num < n) break;
    res = min(res, t-s);
    if (--count[a[s++]] == 0) --num;
  }
  return res;
}

int main(int argc, char** argv) {
  const int P {5};
  std::vector<int> a{1,8,8,8,1};
  std::cout << answer(P, a) << '\n';
}
