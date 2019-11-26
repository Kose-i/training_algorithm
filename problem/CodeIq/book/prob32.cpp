#include <iostream>
#include <vector>

namespace prob32{
  unsigned nCr(const unsigned& n, const unsigned& r, std::vector<std::vector<unsigned>>& memo) {
    if ((r==0) || (r==n)) return 1;
    if (memo[n][r]) return memo[n][r];
    return memo[n][r] = nCr(n-1, r, memo) + nCr(n-1, r-1, memo);
  }
  unsigned answer(const int& station_size) {
    std::vector<std::vector<unsigned>> memo(station_size+1, std::vector<unsigned>(station_size+1, 0));
    unsigned cnt {};
    for (auto i = 2;i < station_size - 1;++i) {
      cnt += nCr(station_size, i, memo) * (station_size - i - 1) * (i - 1);
    }
    return cnt;
  }
}

int main(int argc, char** argv) {
  const int station_size {14};
  std::cout << prob32::answer(station_size) << '\n';
}
