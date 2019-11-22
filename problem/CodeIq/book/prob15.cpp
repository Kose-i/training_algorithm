#include <iostream>

namespace prob15{
  const int M{3000};
  const int N{2500};
  unsigned answer() {
    unsigned pre {};
    unsigned now {1};
    unsigned n = N;

    for (;1 < n;) {
      if ((pre*2 == now) || (pre*2 + 1 == now)) {
        if (now*2 <= M) {
          pre = now;
          now = now*2;
          n = n - 1;
        } else {
          pre = now;
          now = now / 2;
        }
      } else {
        if (pre%2 == 0) {
          if (now*2 +1 <= M) {
            pre = now;
            now = now*2 + 1;
            n = n - 1;
          } else {
            pre = now;
            now = now / 2;
          }
        } else {
          pre = now;
          now = now / 2;
        }
      }
    }
    return now;
  }
}

int main(int argc, char** argv) {
  std::cout << prob15::answer() << '\n';
}
