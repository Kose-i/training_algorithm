#include <iostream>
#include <vector>
#include <limits>

struct edge{
  int from;
  int to;
  int cost;
};
struct Point{
  bool get_minimum_cost;
  int cost;
};
constexpr int INF {std::numeric_limits<int>::max()/2};

void answer(const int& N_node, const std::vector<edge>& vec_path) {
  //initialize
  std::vector<Point> vec_edge(N_node);
  Point tmp;
  tmp.get_minimum_cost = false;
  tmp.cost = INF;
  for (auto& e : vec_edge) {
    e = tmp;
  }
  vec_edge[0].cost = 0;
  //update
  while (true) {
    int v = -1;
    for (int u = 0;u < vec_edge.size();++u) {
      if ((!vec_edge[u].get_minimum_cost) && (v==-1||(vec_edge[u].cost < vec_edge[v].cost))) v = u;
    }
    if (v==-1) break;
    vec_edge[v].get_minimum_cost = true;
    for (const auto& e : vec_path) {
      if (e.from == v) vec_edge[e.to].cost = ((vec_edge[e.from].cost+e.cost) < vec_edge[e.to].cost)?(vec_edge[e.from].cost + e.cost):vec_edge[e.to].cost;
      if (e.to == v) vec_edge[e.from].cost = ((vec_edge[e.to].cost+e.cost) < vec_edge[e.from].cost)?(vec_edge[e.to].cost + e.cost):vec_edge[e.from].cost;
    }
  }
  //output
  for (const auto& e : vec_edge) {
    std::cout << e.cost << '\n';
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
