#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

double calc(const int& N, const int& H, const int& R, const int& T, const double& g) {
  if (T < 0) return H;
  double t = std::sqrt(2*H/g);
  int k = (int)(T/t);
  if (k%2==0) {
    double d = T-k*t;
    return H-g*d*d/2;
  } else {
    double d = k*t + t - T;
    return H-g*d*d/2;
  }
}
void answer(const int& N, const int& H, const int& R, const int& T) {
  const double g {10.0};
  std::vector<double> y(N);
  for (auto i = 0;i < N;++i) {
    y[i] = calc(N, H, R, T-i, g);
  }
  std::sort(y.begin(), y.end());
  for (auto i = 0;i<N;++i) {
    std::cout << y[i] + 2.0*R*i/100.0;
    std::cout << ((i+1==N)?'\n':' ');
  }
}
int main(int argc, char** argv) {
  const int N {2};
  const int H {10};
  const int R {10};
  const int T {100};
  answer(N, H, R, T);
}
