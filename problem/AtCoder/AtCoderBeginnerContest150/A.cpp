#include <iostream>

int main(int argc, char** argv) {
  int K, X;
  std::cin >> K >> X;
  if (500*K >= X) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
