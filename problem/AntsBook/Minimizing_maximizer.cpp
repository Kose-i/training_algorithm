#include <algorithm>
#include <iostream>
#include <vector>

constexpr int INF {1000000};
struct Pair {
  int from, to;
};
bool operator<(struct Pair& l, struct Pair& r) {
  return l.from < r.from;
}
constexpr int min(int a, int b) {
  return (a<b)?a:b;
}

int answer(const int& n, const int& m, std::vector<Pair>& st){
  std::vector<int> dp(n+1, INF);
  dp[1] = 0;
  std::sort(st.begin(), st.end());
  for (auto i = 0;i < m;++i) {
    dp[st[i].to] = min(dp[st[i].to], dp[st[i].from]+1);
  }
  return dp[n];
}

int main(int argc, char** argv) {
  const int n {40};
  const int m {6};
  std::vector<Pair> s_t{{20, 30}, {1, 10}, {10, 20}, {20, 30}, {15, 25}, {30, 40}};
  std::cout << answer(n, m, s_t) << '\n';
}
