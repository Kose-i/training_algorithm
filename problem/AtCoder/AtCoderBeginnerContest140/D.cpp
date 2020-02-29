#include <iostream>
#include <vector>
#include <string>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

ll count_S(const std::vector<char>& S, const int& N) {
  ll cnt {};
  for (auto i = 1;i < N;++i) {
    if (S[i] == S[i-1]) ++cnt;
  }
  return cnt;
}

int main() {
  int N, K;
  std::cin >> N >> K;
  std::vector<char> S(N);
  rep(i, N) std::cin >> S[i];
  ll c {};
  for (int i = 1;i < N;++i) {
    if (S[i] != S[i-1]) ++c;
  }
  ll answer {N-1-c+2*K};
  if (answer > N-1) answer = N-1;
  std::cout << answer << '\n';
}
