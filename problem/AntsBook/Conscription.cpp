#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

struct edge{
  int x,y;
  int d;
};
bool operator<(const edge& e1, const edge& e2) {
  return e1.d < e2.d;
}
int kruskal(const int& node_count, const int& path_count, const std::vector<edge>& es) {
  std::vector<edge> vec_path_temp = es;
  std::sort(vec_path_temp.begin(), vec_path_temp.end());
  std::vector<int> group(node_count, 0);
  std::iota(group.begin(), group.end(), 0);
  int res {};
  for (const auto& path : vec_path_temp) {
    edge e = path;
    if (group[e.x] != group[e.y]) {
      {//group
        int tmp = group[e.y];
        for (auto& f : group) {
          if (f == tmp) f = group[e.x];
        }
      }//group
      res += e.d;
    }
  }
  return res;
}
int answer(const int& N, const int& M, const int& R, const std::vector<edge>& es_vec) {
  int V = N + M;
  int E = R;
  std::vector<edge> es(R);
  for (auto i = 0;i < R;++i) {
    es[i] = (edge){es_vec[i].x, N+es_vec[i].y, -es_vec[i].d};
  }
  return (10000*(N+M)+kruskal(V, E, es));
}

int main(int argc, char** argv) {
  const int N {5};
  const int M {5};
  const int R {8};
  std::vector<edge> es_vec;
  es_vec.push_back((edge){4, 3, 6831});
  es_vec.push_back((edge){1, 3, 4583});
  es_vec.push_back((edge){0, 0, 6592});
  es_vec.push_back((edge){0, 1, 3063});
  es_vec.push_back((edge){3, 3, 4975});
  es_vec.push_back((edge){1, 3, 2049});
  es_vec.push_back((edge){4, 2, 2104});
  es_vec.push_back((edge){2, 2,  781});
  std::cout << answer(N, M, R, es_vec) << '\n';
}
