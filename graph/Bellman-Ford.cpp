#include <iostream>
#include <vector>
#include <limits>

struct edge{
  int from;
  int to;
  int cost;
};
constexpr int INF {std::numeric_limits<int>::max()};

void answer(const int& N_node, const std::vector<edge>& vec_path) {
  std::vector<int> d(N_node, INF);
  d[0] = 0;
  while (true) {
    bool is_update = false;
    for (const auto& path : vec_path) {
      if (d[path.from] != INF && d[path.to] > d[path.from]+path.cost) {
        d[path.to] = d[path.from] + path.cost;
        is_update = true;
      }
      if (d[path.to] != INF && d[path.from] > d[path.to]+path.cost) {
        d[path.from] = d[path.to] + path.cost;
        is_update = true;
      }
    }
    if (is_update == false) break;
  }
  for (const auto& e : d) {
    std::cout << e << '\n';
  }
}

int main(int argc, char** argv) {
  std::vector<edge> vec_path;
  edge tmp;
  tmp.from = 0;tmp.to = 1;tmp.cost = 2;
  vec_path.push_back(tmp);
  tmp.from = 0;tmp.to = 2;tmp.cost = 5;
  vec_path.push_back(tmp);
  tmp.from = 1;tmp.to = 2;tmp.cost = 4;
  vec_path.push_back(tmp);
  tmp.from = 2;tmp.to = 3;tmp.cost = 2;
  vec_path.push_back(tmp);
  tmp.from = 1;tmp.to = 3;tmp.cost = 6;
  vec_path.push_back(tmp);
  tmp.from = 1;tmp.to = 4;tmp.cost = 10;
  vec_path.push_back(tmp);
  tmp.from = 4;tmp.to = 5;tmp.cost = 3;
  vec_path.push_back(tmp);
  tmp.from = 3;tmp.to = 5;tmp.cost = 1;
  vec_path.push_back(tmp);
  tmp.from = 4;tmp.to = 6;tmp.cost = 5;
  vec_path.push_back(tmp);
  tmp.from = 5;tmp.to = 6;tmp.cost = 9;
  vec_path.push_back(tmp);

  answer(7, vec_path);
}
