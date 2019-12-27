#include <iostream>
#include <vector>

struct Pair{
  int from, to;
};
struct Point {
  unsigned long long u, v;
};

template<typename T>
T max_func(const T& l, const T& r) {
  return (l < r)?r:l;
}

unsigned long long answer(const unsigned long long& N, const Point& initial_pos, const std::vector<Pair>& path) {
  std::vector<Point> vec_edge(N+1, {N, N});
  bool is_check = true;
  vec_edge[initial_pos.u].u = 0;
  vec_edge[initial_pos.v].v = 0;
  for (;is_check;) {
    is_check = false;
    for (const auto& e : path) {
      if (vec_edge[e.from].u != vec_edge[e.to].u + 1 || vec_edge[e.from].u+1 != vec_edge[e.to].u) {
        int tmp_min = (vec_edge[e.from].u < vec_edge[e.to].u)?e.from:e.to;
        int tmp_max = (vec_edge[e.from].u > vec_edge[e.to].u)?e.from:e.to;
        vec_edge[tmp_max].u = vec_edge[tmp_min].u + 1;
        is_check = true;
      }
      if (vec_edge[e.from].v != vec_edge[e.to].v + 1 || vec_edge[e.from].v+1 != vec_edge[e.to].v) {
        int tmp_min = (vec_edge[e.from].v < vec_edge[e.to].v)?e.from:e.to;
        int tmp_max = (vec_edge[e.from].v > vec_edge[e.to].v)?e.from:e.to;
        vec_edge[tmp_max].v = vec_edge[tmp_min].v + 1;
        is_check = true;
      }
    }
    unsigned long long max_turn {};
    for (const auto& e : vec_edge) {
      if (e.v > max_turn) {
        max_turn = e.v;
      }
    }
    return max_turn-1;
  }
}

int main(int argc, char** argv) {
  const unsigned long long N {[](){unsigned long long t;std::cin >> t;return t;}()};
  Point initial_point;
  std::cin >> initial_point.u >> initial_point.v;
  std::vector<Pair> A(N-1);
  for (auto& e : A) {
    std::cin >> e.from >> e.to;
  }
  std::cout << answer(N, initial_point, A) << '\n';
}
