#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int H, A;
  std::cin >> H >> A;
  std::cout << ((H%A!=0)?((H/A)+1):(H/A)) << '\n';
}
