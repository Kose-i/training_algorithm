#include <iostream>
#include <vector>

namespace prob62{
  int check(std::vector<int> temp, const int& W, const int& H) {
    std::vector<int> connect(W*H, 0);
    int remain {};
    int single {};
    for (auto i = 0;i < W*H;++i) {
      if (temp[i] == 0) {
        if ((i%W != 0)   && (temp[i-1] == 0)) ++connect[i];
        if ((i%W != W-1) && (temp[i+1] == 0)) ++connect[i];
        if ((i/W != 0)   && (temp[i-W] == 0)) ++connect[i];
        if ((i/W != H-1) && (temp[i+W] == 0)) ++connect[i];
        ++remain;
        if (connect[i] == 1) ++single;
      }
    }
    if (single > 0) {
      for (auto i = 0;i < W*H; ++i) {
        if ((connect[i] == 1) && (temp[i] == 0)) {
          temp[i] = 1;
          if ((i%W != 0) && (temp[i-1] == 0)) {
            temp[i-1] = 1;
          } else if ((i%W != W-1) && (temp[i+1] == 0)) {
            temp[i+1] = 1;
          } else if ((i/W != 0) && (temp[i-W] == 0)) {
            temp[i-W] = 1;
          } else if ((i/W != H-1) && (temp[i+W] == 0)) {
            temp[i+W] = 1;
          } else {
            return 1;
          }
        }
      }
      return check(temp, W, H);
    } else {
      return remain;
    }
  }
  bool search(const int& W, const int& H, const int& pos, const int& depth, std::vector<int>& pins) {
    if (depth == 0) {
      if (check(pins, W, H) == 0) {
        return true;
      }
      return false;
    }
    if (pos == W*H) return false;//TODO
    if (pins[pos] == 0) {
      if ((pos%W < W-1) && (pins[pos + 1] == 0)) {
        pins[pos] = 1;
        pins[pos+1] = 1;
        if (search(W, H, pos, depth-1, pins) == true) return true;
        pins[pos] = 0;
        pins[pos+1] = 0;
      }
      if ((pos/W < H-1) && (pins[pos+W] == 0)) {
        pins[pos] = 1;
        pins[pos+W] = 1;
        if (search(W, H, pos, depth-1, pins) == true) return true;
        pins[pos] = 0;
        pins[pos+W] = 0;
      }
    }
    if (search(W, H, pos + 1, depth, pins) == true) return true;
    return false;// ERROR
  }
  int answer(const int& row_num, const int& column_num) {
    std::vector<int> pins(row_num*column_num, 0);
    int broken {};
    unsigned end_i = row_num*column_num / 2;
    for (auto i = 0;i < end_i;++i) {
      broken = i;
      if ( search(row_num, column_num, 0, broken, pins) ) break;
    }
    return broken;
  }
}

int main(int argc, char** argv) {
  const int row_num {10};
  const int column_num {4};
  std::cout << prob62::answer(row_num, column_num) << '\n';
}
