#include <iostream>
#include <vector>
#include <limits>

struct edge{
  int from;
  int to;
  int cost;
};
constexpr int INF {std::numeric_limits<int>::max()/2};

void answer(const int& N_node, const std::vector<edge>& vec_path) {
  std::vector<std::vector<int>> d(N_node, std::vector<int>(N_node, INF));
  for (auto i = 0;i < N_node;++i) {
    d[i][i] = 0;
  }
  for (auto& e : vec_path) {
    d[e.from][e.to] = e.cost;
    d[e.to][e.from] = e.cost;
  }
  for (auto k = 0;k < N_node;++k) {
    for (auto i = 0;i < N_node;++i) {
      for (auto j = 0;j < N_node;++j) {
        d[i][j] = (d[i][j]<d[i][k]+d[k][j])?d[i][j]:(d[i][k]+d[k][j]);
      }
    }
  }
  for (auto i = 0;i < N_node;++i) {
    std::cout << d[0][i] << '\n';
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
