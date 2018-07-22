#include <iostream>
#include <array>

int gcd(int a,int b) {
  if(b == 0)return a;
  else  gcd(b, a % b);
}
int main(int argc, char** argv) {
  std::array<int,2> number{105,15};
  int greatest_common_divisor = gcd(number[0],number[1]);
  std::cout << greatest_common_divisor << '\n';
}
