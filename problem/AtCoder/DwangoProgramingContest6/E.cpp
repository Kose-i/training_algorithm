#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
  int N;
  int X;
  cin >> N >> X;
  vector<int> seat_vec(N);
  for (auto& e : seat_vec) cin >> e;
  int sum_long {};
  for (const auto& e : seat_vec) sum_long += e;
}
