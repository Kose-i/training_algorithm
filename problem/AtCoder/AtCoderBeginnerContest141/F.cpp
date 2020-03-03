#include <iostream>
#include <vector>

using ull = unsigned long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<ull> A(N);
  rep(i,N) std::cin >> A[i];
}
