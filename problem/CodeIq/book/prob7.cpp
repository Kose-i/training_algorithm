#include <iostream>

namespace prob7{
  unsigned long nPr(const unsigned& n, const unsigned& r) {
    unsigned long nPr_ans {1};
    for (auto i = 0;i < r;++i) {
      nPr_ans *= (n - i);
    }
    return nPr_ans;
  }
  unsigned long answer() {
    constexpr auto book_size = 15;
    unsigned long ans_tmp {};
    for (auto i = 1;i < book_size;++i) {
      ans_tmp += i*(book_size - i) * nPr(book_size, i - 1);
    }
    return ans_tmp;
  }
}
int main(int argc, char** argv) {
  std::cout << prob7::answer() << '\n';
}
