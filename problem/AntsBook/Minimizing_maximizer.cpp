#include <iostream>
#include <vector>

constexpr int INF {1000000};
struct Pair {
  int s, t;
};
constexpr int min(int a, int b) {
  return (a<b)?a:b;
}

int answer(const int& n, const int& m, const std::vector<Pair>& st){
  std::vector<int> dp(n+1, INF);
  for (auto i = 0;i < m;++i) {
    int v = min(dp[st[i].t], query(st[i].s, st[i].t + 1) + 1 );
    dp[st[i].t] = v;
    update(st[i].t, v);
  }
  return dp[n];
}

int main(int argc, char** argv) {
  const int n {40};
  const int m {6};
  const std::vector<Pair> s_t{{20, 30}, {1, 10}, {10, 20}, {20, 30}, {15, 25}, {30, 40}};
  std::cout << answer(n, m, s_t) << '\n';
}
