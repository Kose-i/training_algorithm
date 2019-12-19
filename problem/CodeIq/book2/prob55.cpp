#include <iostream>
#include <vector>

namespace prob55{
  std::vector<int> make_mask(const int& W, const int& H) {
    std::vector<int> masks;
    for (auto h = 0;h < H;++h) {
      for (auto w = 0;w < W;++w) {
        int pos = 1 << (w+h*W);
        if (w > 0)   pos |= 1 << (w-1+h*W);
        if (w < W-1) pos |= 1 << (w+1+h*W);
        if (h > 0)   pos |= 1 << (w+(h-1)*W);
        if (h < H-1) pos |= 1 << (w+(h+1)*W);
        masks.push_back(pos);
      }
    }
    return masks;
  }
  unsigned search(const std::vector<int>& masks, const int& W, const int& H) {
    unsigned end_pos = (1<<(W*H));
    std::vector<int> checked(end_pos, 0);
    checked[0] = 0;
    checked[end_pos-1] = 0;
    std::vector<int> queue(2,0);
    queue[0] = 0;
    queue[1] = end_pos - 1;
    unsigned n {};
    while (queue.size() > 0) {
      std::vector<int> temp;
      for (auto i = 0;i < queue.size();++i) {
        for (const auto& mask : masks) {
          if (!checked[queue[i]^mask]) {
            temp.push_back(queue[i]^mask);
            checked[queue[i]^mask] = n;
          }
        }
      }
      queue = temp;
      ++n;
    }
    return (n-1);
  }
  unsigned answer(const int& W, const int& H) {
    std::vector<int> mask = make_mask(W, H);
    return search(mask, W, H);
  }
}

int main(int argc, char** argv) {
  const int w {6};
  const int h {3};
  std::cout << prob55::answer(w, h) << '\n';
}
