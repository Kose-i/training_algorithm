#include <iostream>
#include <vector>

namespace prob11{
  unsigned long re_answer(const int& size) {
    if (size <= 2)return 1;
    unsigned long v1 = re_answer(size - 1);
    unsigned long v2 {};
    for (auto i = 2; i < size;++i) {
      v2 += re_answer(i);
    }
    return 1 + v1 + v2*v1;
  }

  unsigned long answer(){
    return re_answer(7);
  }
}

int main(int argc, char** argv) {
  std::cout << prob11::answer() <<'\n';
}
