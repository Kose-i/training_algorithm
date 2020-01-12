#include <iostream>
#include <vector>

using namespace std;

struct Test{
  bool is_ok = false;
  int penalty_cnt = 0;
};

int main(int argc, char** argv) {
  int N, M;
  cin >> N >> M;
  vector<Test> seikou(N);
  for (auto i = 0;i < M;++i) {
    int num;
    string s;
    cin >> num >> s;
    if (seikou[num-1].is_ok == false) {
      if (s == "WA") {
        ++seikou[num-1].penalty_cnt;
      } else {
        seikou[num-1].is_ok = true;
      }
    }
  }
  int clear_cnt_game {};
  int penalty_cnt_game {};
  for (const auto& e : seikou) {
    if (e.is_ok == true) {
      ++clear_cnt_game;
      penalty_cnt_game += e.penalty_cnt;
    }
  }
  cout << clear_cnt_game << ' ' << penalty_cnt_game << '\n';
}
