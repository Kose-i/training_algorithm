#include <iostream>
#include <vector>
#include <utility>

struct Status{
  int have_money;
  int time_now;
}

unsigned answer(const int& country_size, const int& now_money, const int& path_size, const std::vector<int>& from_path, const std::vector<int>& to_path, const std::vector<int>& cost, const std::vector<int>& time) {
  std::vector<std::vector<Status>> node(country_size);
  /*ダイクストラ法*/
  for (auto i = 0;i < country_size;++i) {
    for (auto j = 0;j < country_size;++j) {
      if (i == j) continue;
      for (auto k = 0;k < country_size;++k) {
        if (k == i || k == j) continue;
        for (const auto& e : node[i][k]) {
        //  node[i][j].push_back(e+ path[k][j]);
        }
      }
    }
  }
}
int main(int argc, char** argv) {
  int N, C, V;
  std::cin >> N >> C >> V;
  std::vector<int> from(V);
  for (auto& e : from) {std::cin >> e;}
  std::vector<int> to(V);
  for (auto& e : to) {std::cin >> e;}
  std::vector<int> cost(V);
  for (auto& e : cost) {std::cin >> e;}
  std::vector<int> time(V);
  for (auto& e : time) {std::cin >> e;}
  std::cout << answer(N, C, V, from, to, cost, time) << '\n';
}
