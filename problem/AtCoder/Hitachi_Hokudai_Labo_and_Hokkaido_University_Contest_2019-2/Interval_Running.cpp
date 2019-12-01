#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
  long T1 , T2;
  long A1, A2, B1, B2;
  std::cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  long T1_vel = (A1-A2);
  long T2_vel = (B1-B2);
  long up = T1 * T1_vel;
  long down = T2*T2_vel;
  long dis = up - down;
  if (dis == 0 || (A1==A2)) {
    std::cout << "infinity\n";
    return 0;
  }
  if ((up >= 0 && down >= 0) || (up < 0 && down < 0)) {
    std::cout << "0\n";
  }
  std::cout << std::ceil(std::abs(down) / dis) << '\n';
}
