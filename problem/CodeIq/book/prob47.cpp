#include <iostream>

namespace prob47{
  unsigned search(const int& n, const int& c, const int& max_size, const int& max_kind) {
    if (c <= 2) return 0;
    if (n == 1) return max_kind;
    return search(n-1, c, max_size, max_kind) + (max_size - 1)*search(n-1, c-2, max_size, max_kind);
  }
  unsigned answer(const int& size, const int& kind) {
    return search(size, kind, size, kind);
  }
}

int main(int argc, char** argv) {
  const int size {6};
  const int kind {6};
  std::cout << prob47::answer(size, kind) << '\n';
}
