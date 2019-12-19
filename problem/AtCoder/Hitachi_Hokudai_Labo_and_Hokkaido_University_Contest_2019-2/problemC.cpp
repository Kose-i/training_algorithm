#include <iostream>
#include <vector>

struct graph_data{
  int from, to;
  int distance;
  int from_param;
  int to_param;
};
std::istream& operator>>(std::istream& is, graph_data& t) {
  return is >> t.from >> t.to >> t.distance >> t.from_param >> t.to_param;
}
void answer(const int& edge_cnt, const int& neighbor_cnt, const std::vector<graph_data>& G, const std::vector<int>& F, const std::vector<std::vector<int>>& t, const int& P_light, const int& T_warning, const int& T_max) {
  int red_light_waiting_time {};
  int now_pos {}; //TODO
  for (auto i = 0;i < T_max; ++i) {
    std::string car_status; 
    std::getline(std::cin, car_status);
    std::getline(std::cin, car_status);
    std::vector<int> jam(4); for (auto& e : jam) std::cin >> e;
    int N_cancel; std::cin >> N_cancel;
    std::vector<int> cancel_id(N_cancel); for (auto& e : cancel_id) std::cin >> e;
    int N_new; std::cin >> N_new;
    std::vector<int> new_id(N_new); for (auto& e : new_id) std::cin >> e;
    std::vector<int> dst(N_new); for (auto& e : dst) std::cin >> e;
    int N_put; std::cin >> N_put;
    std::vector<int> put_id(N_put); for (auto& e : put_id) std::cin >> e;
    if (car_status == "BROKEN") {
      std::cout << "-1" << std::endl;
      std::string verdict; std::cin >> verdict;
      int N_achieve; std::cin >> N_achieve;
      std::vector<int> achieve_id(N_achieve); for (auto& e : achieve_id) std::cin >> e;
      if (verdict == "OK") continue;
      if (verdict == "NG") return;
    } else if (red_light_waiting_time > 0) {
      --red_light_waiting_time;
      std::cout << "-1" << std::endl;
      std::string verdict; std::cin >> verdict;
      int N_achieve; std::cin >> N_achieve;
      std::vector<int> achieve_id(N_achieve); for (auto& e : achieve_id) std::cin >> e;
      if (verdict == "OK") continue;
      if (verdict == "NG") return;
    }
    //TODO
    if (i%2==0)std::cout << G[0].to << std::endl;
    else std::cout << G[0].from << std::endl;
    std::string verdict; std::cin >> verdict;
    int N_achieve; std::cin >> N_achieve;
    std::vector<int> achieve_id(N_achieve); for (auto& e : achieve_id) std::cin >> e;
    if (verdict == "OK") continue;
    if (verdict == "NG") return;
    //TODO
  }
}
int main(int argc, char** argv) {
  const int edge_cnt {[](){int t;std::cin >> t;return t;}()};
  const int neighbor_cnt {[](){int t;std::cin >> t;return t;}()};
  std::vector<graph_data> G(neighbor_cnt);
  for (auto& e : G) std::cin >> e;
  std::vector<int> F(edge_cnt);
  for (auto& e : F) std::cin >> e;
  std::vector<std::vector<int>> t(4, std::vector<int>(4));
  for (auto& e : t) for (auto& f : e) std::cin >> f;
  const int P_light {[](){int a;std::cin >> a;return a;}()};
  const int T_warning {[](){int a;std::cin >> a;return a;}()};
  const int T_max {[](){int a;std::cin >> a;return a;}()};
  answer(edge_cnt, neighbor_cnt, G, F, t, P_light, T_warning, T_max);
}
