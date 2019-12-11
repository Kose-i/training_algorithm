#include <iostream>
#include <array>

int gcd(int a,int b) {
  if(b == 0)return a;
  else  gcd(b, a % b);
}
int extgcd(const int a, const int b, int& x, int& y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1;y = 0;
  }
  return d;
}

int main(int argc, char** argv) {
  std::array<int,2> number{89,71};
  int greatest_common_divisor = gcd(number[0],number[1]);
  std::cout << greatest_common_divisor << '\n';

  int x, y;
  int greatest_common_divisor_ext = extgcd(number[0],number[1], x, y);
  std::cout << greatest_common_divisor_ext << ' ' << x << ' ' << y << '\n';
}
