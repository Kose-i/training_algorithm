#include <iostream>
#include <cmath>

namespace prob70{
  double answer(const double& M, const double& N) {
    double sum {M + N -1};
    double ave = sum/M;

    double kind {};
    for (auto i = 1;i <= M;++i) {
      if (sum == ave*i + (ave+1)*(M-i)) {
        kind = std::ceil(N*((i / ave) + ((M-i)/(ave+1))));
        break;
      }
    }
    return kind;
  }
}

int main(int argc, char** argv) {
  const double m {10};
  const double n {12};
  std::cout << prob70::answer(m,n) << '\n';
}
