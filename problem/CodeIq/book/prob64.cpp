#include <iostream>

namespace prob64{
  unsigned answer(const int& row_column_sum) {
    unsigned m {};
    unsigned tmp = row_column_sum;
    tmp ^= tmp;
    //unsigned i {};
    std::cout << (0>>1) << '\n';
    return m;
  }
}

int main(int argc, char** argv) {
  const int N {98303};
  std::cout << prob64::answer(N) << '\n';
}
