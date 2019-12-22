#include <iostream>

unsigned long gcd(const unsigned long& A, const unsigned long& B) {
  unsigned long a = (A<B)?B:A;
  unsigned long b = (A>B)?B:A;
  while (true) {
    if (a % b == 0) break;
    int t = a;
    a = b;
    b = t%b;
  }
  return A*B/b;
}
int main(int argc, char** argv) {
  unsigned long A, B;
  std::cin >> A >> B;
  std::cout << gcd(A, B) << '\n';
}
