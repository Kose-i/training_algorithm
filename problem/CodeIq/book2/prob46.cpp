#include <iostream>
#include <map>
#include <vector>

namespace prob46{
  unsigned search(int pos, const int& dir, std::vector<int>& used, const std::map<int,int>& dirs, const int& n, const int& W, const int& H) {
    if (n < 0) return 0;
    if (pos + dir == W*H -1) return (n==0)?1:0;
    if (pos < 0) return 0;

    used[pos] |= dirs.at(dir);

    pos += dir;
    if (pos < 0) return 0;

    used[pos] |= dirs.at(-dir);

    unsigned cnt {};

    for (auto d = dirs.begin(); d != dirs.end(); ++d) {
      int m = n - ((dir == (d->first))?0:1);
      if ((used[pos] & d->second) == 0) cnt += search(pos, d->first, used, dirs, m, W, H);
    }
    used[pos] ^= dirs.at(-dir);
    pos -= dir;
    used[pos] ^= dirs.at(dir);
    return cnt;
  }
  unsigned answer(const int& W, const int& H, const int& N) {
    std::map<int, int> dirs;
    dirs.insert(std::make_pair(1,  0b1));
    dirs.insert(std::make_pair(-1, 0b10));
    dirs.insert(std::make_pair(W,  0b100));
    dirs.insert(std::make_pair(-W, 0b1000));
    std::vector<int> used(N+1, 0);
    for (auto i = 0;i < W*H;++i) used[i] = 0;
    for (auto w = 0;w < W;++w) {
      used[w] |= dirs[-1];
      used[w + (H-1)*W] |= dirs[W];
    }
    for (auto h = 0;h < H; ++h) {
      used[h*W] |= dirs[-1];
      used[(h+1)*W-1] |= dirs[1];
    }
    unsigned cnt {};
    cnt += search(0, 1, used, dirs, N, W, H);
    cnt += search(0, W, used, dirs, N, W, H);
    return cnt;
  }
}

int main(int argc, char** argv) {
  const int vertical_points {22};
  const int row_path {5};
  const int column_path {4};
  std::cout << prob46::answer(row_path, column_path, vertical_points) << '\n';
}
