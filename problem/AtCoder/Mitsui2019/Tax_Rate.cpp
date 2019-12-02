#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
  int a, b;
  bool flag = false;
  std::cin >> a;
  for (b = 1;b <= 50000;++b) {
    if (std::floor(b * 1.08) == a) {
      flag = true;
      break;
    }
    if (b*1.08 > a) {
      break;
    }
  }
  if (flag == true) {
    std::cout << b << '\n';
  } else {
    std::cout << ":(\n";
  }
}
