#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  int t;
  std::cin >> t;
  std::vector<int> a(t);
  std::vector<int> b(t);
  rep(i,t) {
    std::cin >> a[i] >> b[i];
  }
  rep(i,t) {
    int c = b[i] - a[i]; // ascending
    if (c == 0) {
      std::cout << "0\n";
    } else if (c > 0 && c % 2 == 0) {
      std::cout << "2\n";
    } else if (c > 0) {
      std::cout << "1\n";
    } else if (c < 0 && (-c) % 2 == 1) {
      std::cout << "2\n";
    } else {
      std::cout << "1\n";
    }
  }
}
