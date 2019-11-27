#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

struct Box{
  int x;
  int y;
};
namespace prob41{
  unsigned long long search(std::vector<int>& tile_column, std::map<std::vector<int>, unsigned long long>& memo, const std::vector<Box>& box_type, const int& column_size, const int& row_size) {
    if (memo.find(tile_column) != memo.end()) return memo[tile_column];
    auto min_elem_it = std::min_element(tile_column.begin(), tile_column.end());
    if (*min_elem_it == row_size) return 1;

    auto min_index_pos = std::distance(tile_column.begin(), min_elem_it);
    unsigned long long cnt {};
    unsigned box_type_size = box_type.size();
    for (auto i = 0;i < box_type_size;++i) {
      bool check = true;
      for (auto x = 0;x < box_type[i].x;++x) {
        if ( (min_index_pos+x >= column_size) || (tile_column[min_index_pos + x] + box_type[i].y > row_size) ) {
          check = false;
          break;
        } else if (tile_column[min_index_pos + x] != tile_column[min_index_pos]) {
          check = false;
          break;
        }
      }
      if (!check) break;

      for (auto x = 0;x < box_type[i].x;++x) {
        tile_column[min_index_pos + x] += box_type[i].y;
      }
      cnt += search(tile_column, memo, box_type, column_size, row_size);
      for (auto x = 0;x < box_type[i].x;++x) {
        tile_column[min_index_pos + x] -= box_type[i].y;
      }
    }
    memo.insert(std::make_pair(tile_column, cnt));
    return cnt;
  }
  unsigned long long answer(const int& column_size, const int& row_size) {
    std::vector<Box> box_type(4);
    box_type[0].x = 1;
    box_type[0].y = 1;
    box_type[1].x = 2;
    box_type[1].y = 2;
    box_type[2].x = 4;
    box_type[2].y = 2;
    box_type[3].x = 4;
    box_type[3].y = 4;
    std::vector<int> tile_column(column_size, 0);
    std::map<std::vector<int>, unsigned long long> memo;
    return search(tile_column, memo, box_type, column_size, row_size);
  }
}

int main(int argc, char** argv) {
  const int column_size {10};
  const int row_size {10};
  std::cout << prob41::answer(column_size, row_size) << '\n';
}
