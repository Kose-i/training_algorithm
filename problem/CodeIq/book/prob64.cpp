#include <iostream>
#include <algorithm>
#include <string>

namespace prob64{
  unsigned answer(const int& row_column_sum) {
    unsigned m {};
    //unsigned i {};
    std::string s;
    for (int i = 1;i > 0;i =i<<1) {
      if ((i&row_column_sum) != 0) s += "1";
      else s += "0";
    }
    auto it = std::find(s.begin(), s.end(), '0');
    int tmp =  std::distance(s.begin(), it);
    return 1<<tmp;
  }
}

int main(int argc, char** argv) {
  const int N {98303};
  std::cout << prob64::answer(N) << '\n';
}
