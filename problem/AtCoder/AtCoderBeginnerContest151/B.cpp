#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  int N, K, M;
  std::cin >> N >> K >> M;
  vector<int> A(N-1);
  for (auto& e : A) cin >> e;
  int sum_A {};
  for (const auto& e : A) sum_A += e;
  int get_score = N*M - sum_A;
  if (get_score <= K) {
    cout << ((get_score < 0)?0:get_score) << '\n';
  } else {
    cout << "-1\n";
  }
}
