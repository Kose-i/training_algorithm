#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

struct edge{
  int from;
  int to;
  int cost;
};
constexpr int INF {std::numeric_limits<int>::max()};

bool operator<(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}
void answer(const int& N_node, const std::vector<edge>& vec_path) {
  std::vector<edge> vec_path_temp = vec_path;
  std::sort(vec_path_temp.begin(), vec_path_temp.end());
  std::vector<int> group(N_node);
  std::iota(group.begin(), group.end(), 0);
  int res {};
  for (auto i = 0;i < vec_path_temp.size(); ++i) {
    edge  e = vec_path_temp[i];
    if (group[e.from] != group[e.to]) {
      {//group
        int tmp = group[e.to];
        for (auto& f : group) {
          if (f == tmp) f = group[e.from];
        }
      }
      res += e.cost;
    }
  }
  std::cout << res << '\n';
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
