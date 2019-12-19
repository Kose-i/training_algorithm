#include <iostream>

namespace prob42{
  unsigned long long answer(const int& column_size, const int& row_size) {
    unsigned long long inside = (column_size - 1) * (row_size - 1) * 2;
    unsigned long long outside = (column_size + row_size) * 2;
    if ( (column_size != 1) && (row_size != 1) && ((column_size%2==0)||(row_size%2==0)) ) {
      return inside + outside - 2;
    } else {
      return inside + outside;
    }
  }
}

int main(int argc, char** argv) {
  const int column_size {99};
  const int row_size {101};
  std::cout << prob42::answer(column_size, row_size) << '\n';
}
