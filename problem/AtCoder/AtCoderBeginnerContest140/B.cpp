#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  std::vector<int> B(N);
  std::vector<int> C(N-1);
  rep(i,N) std::cin >> A[i];
  rep(i,N) std::cin >> B[i];
  rep(i,N-1) std::cin >> C[i];
  int sum {};
  for (const auto& e : B) sum += e;

  for (auto i = 1;i < N;++i) {
    if (A[i-1]+1 == A[i]) {
      sum += C[A[i-1]-1];
    }
  }
  std::cout << sum << '\n';
}
