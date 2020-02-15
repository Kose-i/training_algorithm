#include <iostream>
#include <vector>
#include <stdio.h>

#define rep(i, n) for(int i = 0;i < (n);++i)

using ll = long long;

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  rep(i, N) std::cin >> a[i];
}
