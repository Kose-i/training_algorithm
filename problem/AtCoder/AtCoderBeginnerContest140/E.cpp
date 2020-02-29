#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

struct P{
  int minest, double_minest;
};

int main() {
  ll N;
  std::cin >> N;
  std::vector<ll> A(N);
  rep(i,N) std::cin >> A[i];
  std::vector<P> sum(N-1);
  for (auto i = 0;i < N-1;++i) {
    if (A[i] < A[i+1]) {
      sum[i].minest        = A[i];
      sum[i].double_minest = A[i+1];
    } else {
      sum[i].minest        = A[i+1];
      sum[i].double_minest = A[i];
    }
  }
}
