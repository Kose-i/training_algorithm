#include <iostream>
#include <vector>
#include <map>

namespace prob60{
  constexpr bool is_same(int t1, int t2, int t3, int t4) {
    return ((t1==t2)&&(t1==t3)&&(t1==t4));
  }
  bool check(const std::vector<int>& board, const int& user) {
    for (auto i = 0;i < 3;++i) {
      if (is_same(user, board[i*3], board[i*3+1], board[i*3+2]) || is_same(user, board[i], board[i+3], board[i+6])) return true;
    }
    if (is_same(user, board[0], board[4], board[8]) || is_same(user, board[2], board[4], board[6])) return true;
    return false;
  }
  int search(std::vector<int>& board, const int& user, std::map<std::vector<int>, std::vector<int>>& memo, std::map<std::vector<int>, unsigned>& uniq) {
    if (memo.find(board)!=memo.end() && memo[board][user]) return memo[board][user];
    if (check(board, (user==1)?2:1)) {
      if (uniq.find(board) != uniq.end()) {
        uniq[board] = 1;
      } else {
        uniq.insert(std::make_pair(board, 1));
      }
      return 1;
    }
    unsigned cnt {};
    for (auto i = 0;i < 9;++i) {
      if (board[i] == 0) {
        board[i] = (user==1)?1:2;
        cnt += search(board, (user==1)?2:1, memo, uniq);
        board[i] = 0;
      }
    }
    if (memo.find(board) != memo.end()) {
      memo[board][user] = cnt;
    } else {
      std::vector<int> tmp(2,0);
      tmp[user] = cnt;
      memo.insert(std::make_pair(board, tmp));
    }
    return cnt;
  }
  void answer() {
    std::vector<int> board(9, 0);
    std::map<std::vector<int>, std::vector<int>> memo;
    std::map<std::vector<int>, unsigned> uniq;
    std::cout << search(board, 1, memo, uniq) << '\n';
    std::cout << uniq.size() << '\n';
  }
}

int main(int argc, char** argv) {
  prob60::answer();
}
