#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string S, T, U;
  int A, B;
  std::cin >> S >> T >> A >> B >> U;
  if (S == U) --A;
  else if (T == U) --B;
  std::cout << A << ' ' << B << '\n';
}
