#include <iostream>
#include <cmath>


namespace problem12{
  const unsigned long pi {314159265358};
  const unsigned N {11};
  unsigned answer(){
    unsigned q {1};
    unsigned long pow = std::pow(10, N);
    for (;true;) {
      if ((q * pi / pow) != (q*(pi+1)/pow)) {
        if (q*(pi+1) % pow >0) {
          return q;
        }
      }
      ++q;
    }
  }
}

int main(int argc, char** argv) {
  std::cout << problem12::answer() << '\n';
}
