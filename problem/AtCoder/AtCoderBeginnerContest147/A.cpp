#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << ((a+b+c>21)?"bust":"win") << '\n';
}
