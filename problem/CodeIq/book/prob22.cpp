#include <iostream>
#include <vector>
#include <limits>

namespace prob22{
  const std::vector<unsigned> line_num{8,6,8,9,3,4,1,7,6,1};
  const std::vector<unsigned> row_num {5,1,1,9,1,6,9,0,9,6};
  unsigned answer() {
    std::vector<std::vector<unsigned>> path(10, std::vector<unsigned>(10, std::numeric_limits<unsigned>::max()));
    for (auto i = 0;i < 10;++i) { // line
      for (auto j = 0;j < 10;++j) { // row
        unsigned down  = (i != 0)?(path[i-1][j]+line_num[i]+row_num[j]):std::numeric_limits<unsigned>::max();
        unsigned right = (j != 0)?(path[i][j-1]+line_num[i]+row_num[j]):std::numeric_limits<unsigned>::max();
        path[i][j] = (down < right)?down:right;
        if (i==0&&j==0)path[0][0] = line_num[0] + row_num[0];
      }
    }
    return path[9][9];
  }
}

int main(int argc, char** argv) {
  std::cout << prob22::answer() << '\n';
}
