#include <iostream>

/*
 c*c ==
 (c - x)*(c + x) = c*c - x*x
 (c - y)*(c + y) = c*c - y*y
 c*c - (x*x + y*y - c*c)
*/
constexpr int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a%b);
}
int main(int argc, char** argv) {
  constexpr int rope {500};

  int cnt {};
  for (auto c = 1;c <= rope/4;++c) {
  //for (auto c = 40;c <= 40;++c) {
    for (auto y = 1;y < c;++y) { // 0<c-y && c+y<2*c
      for (auto x = 1; x <= y;++x) {
        if (y*y + x*x == c*c) {
          if (gcd(y,x)==1) ++cnt;
        }
      }
    }
  }
  std::cout << cnt << '\n';
}

