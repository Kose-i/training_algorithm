#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace prob65{
  bool queen(int& rows, const int& n, const int& N, const int& left, const int& down, const int& right, std::vector<int>& queens) {
    if (n == N) {
      queens[n] = rows;
      return true;
    }
    for (auto i = 0;i < N;++i) {
      int pos = (1<<i);
      if ((pos & (left | down | right)) == 0) {
        queens[n] = pos;
        int l = left  | pos;
        int d = down  | pos;
        int r = right | pos;
        if (queen(pos, n+1, N, l<<1, d, r>>1, queens)) return true;
      }
    }
    return false;
  }
  bool array_and(const std::vector<int>& a, const std::vector<int>& b, const int& N) {
    for (const auto& e1 : a) {
      for (const auto& e2 : b) {
        if ((e1^e2) == 0) return true;
      }
    }
    return false;
  }
  unsigned answer(const int& N) {
    std::vector<int> queens(N, 0);
    int rows {};
    if (!queen(rows, 0, N, 0, 0, 0, queens))throw;

    int white {};
    int black {(1<<N)-1};

    std::map<int, int> fw_log;
    std::map<int, int> bw_log;
    fw_log.insert(std::make_pair(white,0));
    bw_log.insert(std::make_pair(black,0));
    std::vector<int> fw = {white};
    std::vector<int> bw = {black};

    unsigned depth {1};
    while (true) {
      std::vector<int> fw_next;
      std::for_each(fw.begin(), fw.end(), [&](auto& f) {
          std::for_each(queens.begin(), queens.end(), [&](auto& q) {
              int check = f^q;
              if (fw_log.find(check) == fw_log.end()) {
                fw_next.push_back(check);
                fw_log.insert(std::make_pair(check,depth));
              } else if (!fw_log[check]) {
                fw_next.push_back(check);
                fw_log[check] = depth;
              }
            }
          );
        }
      );
      fw = fw_next;
      if (fw.size() == 0 || array_and(fw, bw, N)) break;
      ++depth;

      std::vector<int> bw_next;
      std::for_each(bw.begin(), bw.end(), [&](auto& b) {
          std::for_each(queens.begin(), queens.end(), [&](auto& q) {
              int check = b^q;
              if (bw_log.find(check) == bw_log.end()) {
                bw_next.push_back(check);
                bw_log.insert(std::make_pair(check,depth));
              } else if (!bw_log[check]) {
                bw_next.push_back(check);
                bw_log[check] = depth;
              }
            }
          );
        }
      );
      bw = bw_next;
      if (bw.size() == 0 || array_and(fw, bw, N)) break;
      ++depth;

    }

    if (array_and(fw, bw, N)) {
      return depth;
    } else {
      return 0;
    }
  }
}

int main(int argc, char** argv) {
  const int n {7};
  std::cout << prob65::answer(n) << '\n';
}
