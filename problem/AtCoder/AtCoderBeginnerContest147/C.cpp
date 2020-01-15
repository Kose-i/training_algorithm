#include <numeric>
#include <utility>
#include <iostream>
#include <vector>

using Pair = std::pair<int, int>;

bool is_find(const int& num, const std::vector<std::vector<Pair>>& people, const int& N) {
  int people_dim {};
  for (int c = 1;c!=0;c<<=1) {
    if (c&num) {
      for (const auto& e : people[people_dim]) {
        if (e.second == 1) {
          int k = 1<<e.first;
          if ((k&num) == 0)return false;
        } else {
          int k = 1<<e.first;
          if ((k&num) != 0) return false;
        }
      }
    } else {
      bool is_ok = true;
      for (const auto& e : people[people_dim]) {
        if (e.second == 1) {
          int k = 1<<e.first;
          if ((k&num) == 0) {
            is_ok = false;
            break;
          }
        } else {
          int k = 1<<e.first;
          if ((k&num) != 0) {
            is_ok = false;
            break;
          }
        }
      }
      if (is_ok == true) return false;
    }
    ++people_dim;
    if (people_dim == N) return true;
  }
}
int bit_count(const int& num) {
  int cnt {};
  for (int c = 1;c!=0;c<<=1) {
    if (num & c) ++cnt;
  }
  return cnt;
}
constexpr int max(int a, int b) {
  return (a > b)?a:b;
}

int main(int argc, char** argv) {
  int N {};
  std::cin >> N;
  std::vector<std::vector<Pair>> People(N, std::vector<Pair>());
  for (auto i = 0;i < N;++i) {
    int c;
    std::cin >> c;
    std::vector<Pair> p(c);
    for (auto j = 0;j < c;++j) {
      std::cin >> p[j].first >> p[j].second;
      --p[j].first;
    }
    People[i] = p;
  }
  int num = (1<<N) - 1;
  if (is_find(num, People, N)) {
    std::cout << N << '\n';
    return 0;
  }
  std::vector<int> t(num);
  std::iota(t.begin(), t.end(), 0);
  int max_tmp {};
  for (const auto& e : t) {
    if (is_find(e, People, N)) {
      max_tmp = max(max_tmp, bit_count(e));
    }
  }
  std::cout << max_tmp << '\n';
}
