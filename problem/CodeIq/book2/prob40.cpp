#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using Pair = std::pair<int, int>;
namespace prob40{
  int check(const std::vector<int>& map, const int& max_left) {
    std::queue<Pair> q; // now boats position
    q.push(Pair(0,max_left));
    std::vector<std::vector<int>> log(max_left+1, std::vector<int>(max_left+1, 0));
    log[0][max_left] = 0;
    int left {}, right {};
    while (!q.empty()) {
      {
        Pair t = q.front();
        q.pop();
        left = t.first;
        right = t.second;
      }
      for (int l = left - 1; l <= left  +1; l+=2) { // l = left -1, left +1
        for (auto r = right - 1;r <= right +1; r+=2) { // r = right - 1, right +1
          if (l==r) return log[left][right] + 2;
          if ( (l>=0) && (r<=max_left) && (map[l] == map[r]) ) {
            if ((l < r) && (!log[l][r])) {
              {
                Pair t;
                t.first = l;
                t.second = r;
                q.push(t);
              }
              log[l][r] = log[left][right] + 2;
            }
          }
        }
      }
    }
    return -1;
  }
  int search(std::vector<int>& map, const int& left, const int& max_left, const int& level) {
    map[left] = level;
    if (left == max_left) {
      return check(map, max_left);
    }
    int max = -1;
    if (level > 0) {
      int tmp = search(map, left +1, max_left, level -1);
      max = (max > tmp)?max:tmp;
    }
    if (left + level < max_left) {
      int tmp = search(map, left +1, max_left, level +1);
      max = (max > tmp)?max:tmp;
    }
    return max;
  }
  int answer(const int& size) {
    std::vector<int> map(size+1, 0);
    return search(map, 0, size, 0);
  }
}

int main(int argc, char** argv) {
  const int boat_size {12};
  std::cout << prob40::answer(boat_size) << '\n';
}
