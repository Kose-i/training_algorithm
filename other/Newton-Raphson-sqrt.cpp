#include <iostream>

double sqrt(double k) {
  double ans {};
  while(ans * ans < k) {
    ++ans;
  }
  for(int i {};i < 10 ;++i) {
    ans = (ans + k/ans)/2.0;
  }
  return ans;
}

int main() {
  const double quest{[](){double a;std::cin >> a;return a;}()};
  std::cout << sqrt(quest) << '\n';
}
