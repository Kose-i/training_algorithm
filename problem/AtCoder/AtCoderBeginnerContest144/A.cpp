#include <iostream>

int main(int argc, char** argv) {
  int A, B;
  std::cin >> A >> B;
  if ( 0 < A && A < 10 && 0 < B && B < 10) {
    std::cout << A*B << '\n';
  } else {
    std::cout << "-1\n";
  }
}
