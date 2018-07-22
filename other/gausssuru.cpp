#include <iostream>
#include <cmath>
#include <iomanip>

double GaussLegendre(int n) {
  double a = 1.0, b = 1.0 / std::sqrt(2.0), t = 1.0 / 4, p = 1.0, tmp = 0;
  for (int i = 0; i < n; i++) {
    tmp = a;
    a = (tmp + b) / 2;
    b = sqrt(tmp * b);
    t = t - (p * (a - tmp) * (a - tmp));
    p = 2 * p;
  }
  return (a + b) * (a + b) / (4 * t);
}

int main(int argc, char** argv){
  std::cout << __func__ << '\n';
  std::cout << GaussLegendre(1) << '\n';
  std::cout << GaussLegendre(2) << '\n';
  std::cout << GaussLegendre(3) << '\n';
  std::cout << GaussLegendre(4) << '\n';
  return 0;
}

