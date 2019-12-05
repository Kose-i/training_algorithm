#include <iostream>
#include <vector>
#include <queue>

int answer(const int& N, const int& L, const int& P, const std::vector<int>& A, const std::vector<int>& B) {
  std::vector<int> tank_station_pos = A;
  tank_station_pos.push_back(L);
  std::vector<int> tank_station_fuel = B;
  tank_station_fuel.push_back(0);
  std::priority_queue<int> que;
  int ans {};
  int now_pos=0, now_tank = P;
  for (auto i = 0;i < N;++i) {
    int d = tank_station_pos[i] - now_pos;
    while (now_tank - d < 0) {
      if (que.empty()) {
        return -1;
      }
      now_tank += que.top();
      que.pop();
      ++ans;
    }
    now_tank -= d;
    now_pos = tank_station_pos[i];
    que.push(tank_station_fuel[i]);
  }
  return ans;
}

int main(int argc, char** argv) {
  int N, L, P;
  std::cin >> N >> L >> P;
  std::vector<int> A(N);
  for (auto& e : A) {std::cin >> e;}
  std::vector<int> B(N);
  for (auto& e : B) {std::cin >> e;}
  std::cout << answer(N, L, P, A, B) << '\n';
}
