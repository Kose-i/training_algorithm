#include <iostream>

int main(int argc, char** argv) {
  int A, B;
  std::cin >> A >> B;
  int tmp = (A - 2*B);
  if (tmp < 0) tmp = 0;
  std::cout << tmp << '\n';
}
