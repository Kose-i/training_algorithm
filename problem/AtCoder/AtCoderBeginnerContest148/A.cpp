#include <iostream>

int main(int argc, char** argv) {
  int a, b;
  std::cin >> a >> b;
  int up = (a<b)?a:b;
  int down = (a>b)?a:b;
  if (up == 1 && down == 2) std::cout << "3\n";
  else if (up == 1 && down == 3) std::cout << "2\n";
  else std::cout << "1\n";
}
