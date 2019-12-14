#include <iostream>
#include <vector>

struct Point{
  int x, y;
};
Point operator+(const Point& left, const Point& right) {
  return Point{left.x+right.x, left.y+right.y};
}
const std::vector<Point> d_pos {{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}};
int get(const int& x, const int& y, const int& M, const int& N,  const std::vector<std::vector<int>>& map, const std::vector<std::vector<int>>& flip) {
  Point now {x, y};
  int c = map[now.x][now.y];
  for (auto pos_change : d_pos) {
    Point flip_change_pos = now+pos_change;
    if ((0<=flip_change_pos.x && flip_change_pos.x<M)&&(0<=flip_change_pos.y && flip_change_pos.y<N)) {
      c += flip[flip_change_pos.x][flip_change_pos.y];
    }
  }
  return c%2;
}
int calc(const int& M, const int& N, const std::vector<std::vector<int>>& map, std::vector<std::vector<int>>& flip) {
  //flip define
  for (auto i = 1;i < M;++i) {
    for (auto j = 0;j < N;++j) {
      if (get(i-1, j, M, N, map, flip) != 0) flip[i][j] = 1;
    }
  }
  for (auto j = 0;j < N;++j) {
    if (get(M-1, j, M, N, map, flip) != 0) return -1;
  }
  int res_cnt {};
  for (auto i = 0;i < M;++i) {
    for (auto j = 0;j < N;++j) {
      res_cnt += flip[i][j]; // flip[i][j] == (0 or 1)
    }
  }
  return res_cnt;
}
void answer(const int& M, const int& N, const std::vector<std::vector<int>>& map) {
  int res {-1};
  int end_i {1<<N};
  std::vector<std::vector<int>> opt(M, std::vector<int>(N, 0));
  for (auto i = 0;i < end_i;++i) {
    std::vector<std::vector<int>> flip(M, std::vector<int>(N, 0));
    for (auto j = 0;j < N;++j) {
      flip[0][N-j-1] = (i>>j)&1;
    }
    int num = calc(M, N, map, flip);
    if (0 <= num && (res < 0 || num < res)) {
      res = num;
      opt = flip;
    }
  }
  if (res < 0) {
    std::cout << "IMPOSSIBLE\n";
  } else {
    for (const auto& e : opt) {
      for (const auto& f : e) {
        std::cout << f << ' ';
      }
      std::cout << '\n';
    }
  }
}
int main(int argc, char** argv) {
  const int M {4};
  const int N {4};
  std::vector<std::vector<int>> map{
    {1, 0, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {1, 0, 0, 1}
  };
  answer(M, N, map);
}
