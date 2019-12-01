#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

namespace prob67{
  constexpr unsigned max(unsigned t1, unsigned t2) {
    return (t1 > t2)?t1:t2;
  }
  std::vector<std::vector<long>> combination(const std::vector<long>& maze_array, const int& n) {
    std::vector<std::vector<long>> result;
    if (n == 0) return result;
    for (auto i = 0;i < maze_array.size(); ++i) {
      if (n > 1) {
        std::vector<std::vector<long>> combi = combination(std::vector<long>(maze_array.begin()+i+1, maze_array.end()), n-1);
        for (auto j = 0;j < combi.size(); ++j) {
          std::vector<long> t(combi[j].begin(), combi[j].end());
          t.push_back(maze_array[i]);
          result.push_back(t);
        }
      } else {
        std::vector<long> t;
        t.push_back(maze_array[i]);
        result.push_back(t);
      }
    }
    return result;
  }
  bool enable(const long& maze, const long& MASK, const std::vector<std::function<long(long)>>& move, const int& W, const int& H) {
    long start_pos = (1<<(W*H-1));
    long man = start_pos & (MASK - maze);
    if (man == 0) return false;
    for (auto i = 0;i < W*H;++i) {
      long next_man = man;
      for (auto func : move) {
        next_man |= func(man);
      }
      next_man &= (MASK - maze);
      if (next_man&1 == 1) return true;
      if (man == next_man) break;
      if (next_man == 0) break;
      man = next_man;
    }
    return false;
  }
  unsigned search(long maze, long pos, int dir, int depth, const std::vector<std::function<long(long)>>& move, const long& MASK) {
    if (pos == 1) return depth; // Goal position is 1
    for (auto i = 0;i < move.size();++i) {
      int d = (dir - 1 + i + move.size()) % move.size();
      if ((move[d](pos) & (MASK - maze)) > 0) {
        return search(maze, move[d](pos), d, depth+1, move, MASK);
      }
    }
    return 0;
  }
  unsigned answer(const int& W, const int& H, const int& n) {
    long MASK = (1<<(W*H)) - 1;
    long left {};
    long right {};
    for (auto i = 0;i < H;++i) {
      left = (left << W) | ((1<<(W-1)) - 1);
      right = (right<<W) | ((1<<W) - 2);
    }
    std::vector<std::function<long(long)>> move{
                                        [=](const long& m){return (m>>1)&left;},
                                        [=](const long& m){return (m>>1)&left;},
                                        [=](const long& m){return (m<<W)&MASK;},
                                        [=](const long& m){return (m<<1)&right;},
                                        [=](const long& m){return (m>>W)&MASK;}
                                        };
    unsigned max_value {};
    std::vector<long> maze_array(W*H, 0);
    std::iota(maze_array.begin(), maze_array.end(), 0);
    for (long e : maze_array) {
      if (enable(e, MASK, move, W, H)) {
        long start_pos {1<<(W*H-1)};
        max_value = max(search(e, start_pos, 3, 1, move, MASK), max_value);
      }
    }
    return max_value;
  }
}

int main(int argc, char** argv) {
  const int w {4};
  const int h {7};
  const int n {4};
  std::cout << prob67::answer(w, h, n) << '\n';
}
