#include <iostream>

namespace prob6{
  class Box{
    private:
      unsigned long_line, short_line;
    public:
      Box(unsigned x, unsigned y) {
        long_line = std::max(x,y);
        short_line = std::min(x,y);
      }
      unsigned get_long_line() {return long_line;}
      unsigned get_short_line() {return short_line;}
  };
  unsigned answer() {
    unsigned ans_tmp {};
    return ans_tmp;
  }
}

int main(int argc, char** argv) {
  std::cout << prob6::answer() << '\n';
}
