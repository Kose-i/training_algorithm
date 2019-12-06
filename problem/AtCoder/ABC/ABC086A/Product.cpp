#include <iostream>

int main(int argc, char** argv) {
  const int a{[](){int a;std::cin >> a;return a;}()};
  const int b{[](){int a;std::cin >> a;return a;}()};
  if (a % 2 == 0 || b % 2 == 0) {
    std::cout << "Even\n";
  } else {
    std::cout << "Odd\n";
  }
}
