#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
  int N; cin >> N;
  vector<string> s(N);
  vector<int> t(N);
  for (auto i = 0;i < N;++i) {
    cin >> s[i] >> t[i];
  }
  string X; cin >> X;
  bool is_add = false;
  int sum_time {};
  for (auto i = 0;i < N;++i) {
    if (s[i] == X) {
      is_add = true;
    } else if (is_add == true) {
      sum_time += t[i];
    }
  }
  cout << sum_time << '\n';
}
