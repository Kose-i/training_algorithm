#include <iostream>
#include <vector>
#include <utility>

struct Status{
  int have_money;
  int time_now;
}
unsigned answer(const int& country_size, const int& now_money, const int& path_size, const std::vector<int>& from_path, const std::vector<int>& to_path, const std::vector<int>& cost) {
  std::vector<std::vector<Status>> node(country_size);
  Status initial_status;
  initial_status.have_money = now_money;
  initial_status.time_now = 0;
  node[0].push_back(initial_status);
  /*ダイクストラ法*/
}
int main(int argc, char** argv) {
  int N, C, V;
  std::cin >> N >> C >> V;
  std::vector<int> from(V);
  for (auto& e : from) {std::cin >> e;}
  std::vector<int> to(V);
  for (auto& e : to) {std::cin >> e;}
  std::vector<int> cost(V);
  for (auto& e : to) {std::cin >> e;}
  std::cout << answer(N, C, V, from, to, cost) << '\n';
}
