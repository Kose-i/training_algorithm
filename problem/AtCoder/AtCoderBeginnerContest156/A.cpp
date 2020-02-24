#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main() {
  int N, R;
  std::cin >> N >> R;
  if (N < 10) std::cout << R+(100*(10-N)) << '\n';
  else std::cout << R << '\n';
}
