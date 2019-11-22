#include <iostream>
#include <vector>

namespace prob18{
  const unsigned N {16};
  unsigned steps(std::vector<int>& memo, int n) {
    if (memo[n]) return memo[n];
    int none = ~n;
    int movable = (none << 1) + 1;
    int moved = (n & (~movable)) | ((n>>1) & none);
    return memo[n] = 1+steps(memo, moved);
  }
  unsigned answer(){
    unsigned max_size = 1<<N;
    std::vector<int> memo(max_size, 0);
    memo[0] = 0;
    memo[1] = 1;
    unsigned sum {};
    for (auto i = 1;i < max_size;++i) {
      sum += steps(memo, i);
    }
    return sum;
  }
}

int main(int argc, char** argv) {
  std::cout << prob18::answer() << '\n';
}
