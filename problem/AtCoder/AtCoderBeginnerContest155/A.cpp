#include <iostream>
#include <vector>

using ll = long long;

int main(int argc, char** argv) {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a == b && a != c) {
    std::cout << "Yes\n";
  } else if (a == c && a != b) {
    std::cout << "Yes\n";
  } else if (b == c && a != b) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
