#include <iostream>
#include <cmath>
#include <iomanip>

int main(int argc, char** argv) {
  int a, b, x;
  std::cin >> a >> b >> x;
  std::cout << std::fixed << std::setprecision(10);
  if (b*a*a/2 > x) { //triangle
    double l = x / static_cast<double>(a*b);
    double theta = 90 - (180/M_PI)*std::atan(l / b);
    if (theta < 0) theta += 90;
    if (theta >= 90) theta -= 90;
    std::cout << theta << '\n';
  } else {
    double l = (2*x / static_cast<double>(a*a)) - b;
    double theta = 90 - (180/M_PI)*std::atan(a/(b-l));
    if (theta < 0) theta += 90;
    if (theta >= 90) theta -= 90;
    std::cout << theta << '\n';
  }
}
