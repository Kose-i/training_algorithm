#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main() {
  ll N, K;
  std::cin >> N >> K;
  ll answer {1};
  while (N / K != 0) {
    N /= K;
    ++answer;
  }
  std::cout << answer << '\n';
}
