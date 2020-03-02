#include <iostream>
#include <vector>

using ll = unsigned long long;

#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<ll> x(N);
  std::vector<ll> y(N);
  std::vector<ll> a(N);
  std::vector<ll> b(N);
  rep(i, N) std::cin >> x[i] >> y[i] >> a[i] >> b[i];
  for (auto i = 0;i < N;++i) {
    ll distance = y[i] - x[i];
    ll partial = a[i] + b[i];
    if (distance % partial == 0) {
      std::cout << distance / partial << '\n';
    } else {
      std::cout << "-1\n";
    }
  }
}
